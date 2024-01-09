#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include "PowerUps.h"
#include "PowerDowns.h"
#include <libxl.h>
using namespace libxl;



grid::grid(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{

	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick ** [rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;

	point Ballleft;
	Ballleft.x = 60;
	Ballleft.y = 60;

	colected = new collectable * [8];
	colected[0] = new FireBall(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[1] = new WindGlide(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[2] = new WidePaddle(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[3] = new Magnet(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[4] = new MultipleBalls(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[5] = new ReverseDirection(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[6] = new QuickSand(Ballleft, config.BallRad, config.BallRad, pGame);
	colected[7] = new ShrinkPaddle(Ballleft, config.BallRad, config.BallRad, pGame);
	

}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;
	delete colected;
}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)

	//Here we assume that the above checks are passed
	
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y-uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y+ gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HRD:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_ROCK:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new Rock(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
		//TODO: 
		// handle more types
	}
	return 1;
}
void grid::deleteBrick(point clicked)
{
	
	int gridCellRowIndex = (clicked.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clicked.x / config.brickWidth;
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;
	
	
	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr) {
		delete brickMatrix[gridCellRowIndex][gridCellColIndex];
		cout << newBrickUpleft.x << endl << newBrickUpleft.y << endl;
		brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
		pGame->getWind()->SetPen(LAVENDER, 1);
		pGame->getWind()->SetBrush(LAVENDER);
		pGame->getWind()->DrawRectangle(newBrickUpleft.x, newBrickUpleft.y,  newBrickUpleft.x + config.brickWidth, newBrickUpleft.y + config.brickHeight ,FILLED);
	}
	
}

brick*** grid::getbrickmatrix()
{
	return brickMatrix;
}

point grid::collisionAction()
{
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] != nullptr) {
				auto BrickBallCollide = brickMatrix[i][j]->isColliding(pGame->getball(), brickMatrix[i][j]);
				if (BrickBallCollide.collision) {
					// Handle brick-ball collision
					brickMatrix[i][j]->collisionAction();
					// Reflect the ball's direction

					pGame->getball()->reflectball(brickMatrix[i][j]);
						

					/*point index;*/
					index.x = i;
					index.y = j;
					if (brickMatrix[i][j]->stren <= 0)
					{
						point newpoint;
						newpoint = brickMatrix[i][j]->getpoint();
						newpoint.x += config.brickWidth / 2;
						newpoint.y += config.brickHeight / 2;
						
						this->deleteBrickOncollison(index);
						if (config.breaked == 1 && config.getcollectedtimer) {

							/*config.collecteditems = rand() % 8;*/
							cout << config.collecteditems;
							colected[config.collecteditems]->setpoint(newpoint);
							colected[config.collecteditems]->draw();
							config.getcollected = true;
							config.getcollectedtimer = false;
							config.breaked = 0;
							random = rand() % 3;
							pGame->getWind()->UpdateBuffer();

							
						}

					}
					
			
				}
			}
		}
	}
	return index;
}

void grid::deleteBrickOncollison(point index)

{
	
	int gridCellRowIndex = index.x;
	int gridCellColIndex = index.y;
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellRowIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + gridCellColIndex * config.brickHeight;
	

	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr) {
		delete brickMatrix[gridCellRowIndex][gridCellColIndex];
		brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
		config.breaked++;
		
		pGame->getWind()->SetPen(LAVENDER, 1);
		pGame->getWind()->SetBrush(LAVENDER);
		pGame->getWind()->DrawRectangle(newBrickUpleft.x, newBrickUpleft.y, newBrickUpleft.x + config.brickWidth, newBrickUpleft.y + config.brickHeight, FILLED);
	}
	
	

}

collectable** grid::getcollected()
{
	return colected;
}

void grid::save()
{
	
	Book* book = xlCreateBook();
	int col = 0;
	int row = 0;
	if (book) {
		Sheet* sheet = book->addSheet("Sheet1");
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {

				if (sheet)
				{
					if (brickMatrix[i][j] != nullptr) {
						sheet->writeNum(row, col++, i);
						sheet->writeNum(row, col++, j);
						sheet->writeNum(row , col++,brickMatrix[i][j]->getType());
						row++;
						col = 0;
					}


				}

			}
		}
		book->save("example.xls");
		book->release();
	}
	pGame->printMessage("Saved");
}
void grid::load()
{
	Book* book = xlCreateBook();
	int values[3] = { 0,0,0 };
	int count = 0;
	if (book->load("example.xls"))
	{
		Sheet* sheet = book->getSheet(0);
		if (sheet)
		{
			for (int row = sheet->firstRow(); row < sheet->lastRow(); ++row)
			{
				for (int col = sheet->firstCol(); col < sheet->lastCol(); ++col)
				{
					CellType cellType = sheet->cellType(row, col);
					int d = sheet->readNum(row, col);
					values[count++] = d;
					
					
				}
				cout << endl;
				for (int i = 0; i < 3; i++) {
					cout << values[i] << "\t";


				}
				count = 0;

			}
			
			
			
		}
	}

	book->release();
	
}





					//void grid::randomPoint()
					//{
					//	point randomPoint;
					//	randomPoint.x = uprLft.x + (rand() % (config.windWidth / config.brickWidth)) * config.brickWidth;
					//	randomPoint.y = uprLft.y + (rand() % (config.gridHeight / config.brickHeight)) * config.brickHeight;
					//	BrickType randomBrickType = static_cast<BrickType>(rand() % 3);
					//	int gridCellRowIndex = (randomPoint.y - uprLft.y) / config.brickHeight;
					//	int gridCellColIndex = (randomPoint.x - uprLft.x) / config.brickWidth;
					//
					//	// Now, align the upper left corner of the new brick with the corner of the clicked grid cell
					//	point newBrickUpleft;
					//	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
					//	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;
					//
					//	switch (randomBrickType)
					//	{
					//	case BRK_NRM: // The new brick to add is Normal Brick
					//		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
					//		break;
					//	case BRK_HRD: // The new brick to add is Hard Brick
					//		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
					//		break;
					//	case BRK_ROCK: // The new brick to add is Rock
					//		brickMatrix[gridCellRowIndex][gridCellColIndex] = new Rock(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
					//		break;
					//		// TODO: Handle more types
					//	}
					//	
					//
					//}
				