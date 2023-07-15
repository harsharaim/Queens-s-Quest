#include <GL/glut.h>
#include<iostream>
#include <cmath>
using namespace std;

//--------------------Declaration of variables-----------------------------
char chessboard[25][25] = {};
int queens =4;
float W;
float H;
int savingposition[25][2] = {};//array to keep track of the valid positions
int mouseX = 0;
int mouseY = 0;
bool mouseButton = false;
int viewPage = 0;
int queenCount=0;
bool displayBlock = false;
int displayTime = 5000;
//------------------------------------------------------------------------


//-------------------function to display text-----------------------------
void displayText(float x, float y, float z, const char* text) {
	glRasterPos3f(x, y, z);
	for (const char* c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void displayTitle(float x, float y, float z, const char* text) {
	glRasterPos3f(x, y, z);
	for (const char* c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
//-----------------------------------------------------------------------


//-------------------starting information page---------------------------
void info_page(){
    glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(20);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-1000 ,-1000);
		glVertex2f(-1000 ,1000);
		glVertex2f(1000 ,1000);
		glVertex2f(1000 ,-1000);
	glEnd();
	glColor3f(1.0, 0.6, 0.2);
	displayText(-380, 700, 0.0, "SAHYADRI COLLEGE OF ENGINEERING & MANAGEMENT");
	glColor3f(1.0, 1.0, 1.0);
	displayText(-405, 610, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f(1.0, 1.0, 1.0);
	displayText(-175, 500, 0.0, "A MINI PROJECT TITLED ");
	glColor3f(0.0, 1.0, 0.0);
	displayTitle(-150, 350, 0.0, "QUEEN'S QUEST");
	glColor3f(1.0, 0.6, 0.2);
	displayText(-75, 230, 0.0, "created by");
	glColor3f(1.0, 1.0, 1.0);
	displayText(-550, 0, 0.0, "Harsha Kumar Rai M");
	displayText(-550, -85, 0.0, "(*********)");
	displayText(350, 0, 0.0, "Jaideep D Naik");
	displayText(350, -85, 0.0, "(*********)");
	glColor3f(1.0, 0.6, 0.2);
	displayText(-150, -300, 0.0, "Under the Guidance of");
	glColor3f(1.0, 1.0, 1.0);
	displayText(-110, -380, 0.0, "Prof.************");
	glColor3f(1.0, 0.6, 0.2);
	displayText(-180, -500, 0.0, "Academic Year 2022-2023");
	glColor3f(1.0, 1.0, 1.0);
	displayText(-350, -650, 0.0, "Press ENTER to start the game. Press ESC to close.");
	glFlush();
}
//-------------------------------------------------------------------------


//---------------------Game start menu page--------------------------------
void start_page()
{
	glLineWidth(20);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-1000 ,-1000);
		glVertex2f(-1000 ,1000);
		glVertex2f(1000 ,1000);
		glVertex2f(1000 ,-1000);
	glEnd();
    glColor3f(1,0.5,0);
	displayTitle(-150,600,0,"QUEEN'S QUEST");
	glLineWidth(1);
    //start game button
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(-200 ,300);
		glVertex2f(-200 ,425);
		glVertex2f(200 ,425);
		glVertex2f(200 ,300);
	glEnd();
	glColor3f(0 , 0, 0);
	displayTitle(-75 ,340 ,0.4 ,"Start Game");
    if(mouseX>=-100 && mouseX<=100 && mouseY>=325 && mouseY<=400){
		if(mouseButton){
			viewPage =3;
			mouseButton = false;
		}
	}
    //instruction button
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(-200, 75);
		glVertex2f(-200 ,200);
		glVertex2f(200 ,200);
		glVertex2f(200 ,75);
	glEnd();
    glColor3f(0 , 0, 0);
    displayTitle(-83 ,110 ,0.4 ,"Algorithm");
    if(mouseX>=-100 && mouseX<=100 && mouseY>=80 && mouseY<=180){
		if(mouseButton){
			viewPage =2;
			mouseButton = false;
		}
	}
    // go back button
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(-200 ,-150);
		glVertex2f(-200 ,-25);
		glVertex2f(200, -25);
		glVertex2f(200, -150);
	glEnd();
	glColor3f(0 , 0, 0);
	displayText(-50 ,-100 ,0.4 ,"Go Back");
    if(mouseX>=-100 && mouseX<=100 && mouseY>=-130 && mouseY<=-40){
		if(mouseButton){
			viewPage =0;
			mouseButton = false;
		}
	}
	// quit button
    glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2f(-200, -450);
		glVertex2f(-200 ,-325);
		glVertex2f(200 ,-325);
		glVertex2f(200 ,-450);
	glEnd();
	glColor3f(1 , 1, 1);
	displayText(-30 ,-400 ,0.4 ,"Quit");
	if(mouseX>=-100 && mouseX<=100 && mouseY>=-440 && mouseY<=-320){
		if(mouseButton){
			mouseButton = false;
			exit(0);
		}
	}
}
//------------------------------------------------------------------------


//----------------------Algorithm page------------------------------------
void instruction_page(){
    glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(20);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-1000 ,-1000);
		glVertex2f(-1000 ,1000);
		glVertex2f(1000 ,1000);
		glVertex2f(1000 ,-1000);
	glEnd();
	glColor3f(1,0.5,0);
	displayTitle(-280,800,0,"QUEEN'S QUEST ALGORITHM");
    // back button
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
		glVertex2f(-950 ,800);
		glVertex2f(-950 ,900);
		glVertex2f(-800, 900);
		glVertex2f(-800, 800);
	glEnd();
	glColor3f(1,0.5,0);
	displayTitle(-940,830,0,"<- Back");
	if(mouseX>=-950 && mouseX<=-800 && mouseY>=800 && mouseY<=900){
		if(mouseButton){
			viewPage =1;
			mouseButton = false;
		}
	}
    // Algorithms
	glColor3f(0,1,0);
    displayTitle(-940,600,0,"The N Queen is the problem of placing N chess queens on an NxN chessboard so that no two queens attack each other");
	displayTitle(-940,500,0,"It can be seen that for n =1, the problem has a trivial solution, and no solution exists for n =2 and n =3. ");
	displayTitle(-940,400,0 ,"So first we will consider the 4 queens problem and then generate it to n - queens problem.");
    displayTitle(-800,200,0 ,"!!!Algorithm for N-Queens Problem using Backtracking!!!");
	displayText(-940,100,0,"Step 1 - Initialize an empty chessboard of size NxN.");
	displayText(-940,0,0,"Step 2 - Start with the leftmost column and place a queen in the first row of that column.");
	displayText(-940,-100,0,"Step 3 - Move to the next column and place a queen in the first row of that column.");
	displayText(-940,-200,0,"Step 4 - Repeat step 3 until either all N queens have been placed or it is impossible to place a queen in the current column ");
	displayText(-800,-300,0,"without violating the rules of the problem.");
	displayText(-940,-400,0,"Step 5 - If all N queens have been placed, print the solution.");
	displayText(-940,-500,0,"Step 6 - If it is not possible to place a queen in the current column without violating the rules of the problem, backtrack to the previous column.");
	displayText(-940,-600,0,"Step 7 - Remove the queen from the previous column and move it down one row.");
	displayText(-940,-700,0,"Step 8 - Repeat steps 4-7 until all possible configurations have been tried.");
}
//-----------------------------------------------------------------------------


//--------------------------function to draw the shape of the queen------------
void drawQueenCrown() {
    glColor3f(0.0, 0.0, 0.0);
    // Draw the base of the crown
    glBegin(GL_QUADS);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.3, 0.0);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.4, -0.3);
    glEnd();
    // Draw the triangles projecting from the base
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.36, 0.0);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.36, 0.0);
    glEnd();
    // Draw circles at the end of each triangle
    const float radius = 0.07;
    const int numSegments = 30;
    const float angleIncrement = 2.0 * 3.14 / numSegments;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.36, 0.0);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = -0.36 + radius * cos(angle);
        float y = 0.0 + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.4);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = 0.0 + radius * cos(angle);
        float y = 0.4 + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.36, 0.0);
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = 0.36 + radius * cos(angle);
        float y = 0.0 + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
//---------------------------------------------------------------------------------


//---------------------function to display the chess board and queens---------------
void displayboard(){
    glTranslatef(25, H - 25, 0.0);
    glPushMatrix();
    for (int i = 0; i < queens; i++){
        glPushMatrix();
        for (int j = 0; j < queens; j++){
            if ((i + j) % 2 == 0)
                glColor4f(0.99, 0.8, 0.6, 1.0);
            else
                glColor4f(0.82, 0.55, 0.27, 1.0);
            glPushMatrix();
            glScalef(50.0, 50.0, 0.0);
            glutSolidCube(1);
            if (chessboard[i][j] == 'Q'){
                glPushMatrix();
                glColor3f(1, 0, 0);
                drawQueenCrown();
                glPopMatrix();
            }
            glPopMatrix();
            glTranslatef(50.0, 0.0, 0.0);
        }
        glPopMatrix();
        glTranslatef(0.0, -50.0, 0.0);
    }
    glPopMatrix();
}
//--------------------------------------------------------------------------------------------


//---------checking the validity of placing a queen at a given position------------------------
bool checking(int row, int column){
    for (int i = 0; i < queens; i++){
        for (int j = 0; j < queens; j++){
            if ((j + i == column + row || column - row == j - i || i == row || j == column) && chessboard[i][j] == 'Q')
                return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------------------------


//------------clear any previously marked valid positions in the (next) row---------------------
void removeflag(int row){
    for (int i = 0; i < queens; i++){
        chessboard[row][i] = '0';
    }
}
//----------------------------------------------------------------------------------------------


//----------------------function to get the solution for the problem using backtracking---------
void backtracking(void){
    for (int row = 0; row < queens; row++){
        for (int column = 0; column < queens; column++){
            if (checking(row, column) && chessboard[row][column] != '-'){
                chessboard[row][column] = 'Q';
                removeflag(row + 1);
                savingposition[row][0] = row;
                savingposition[row][1] = column;
                row++;
                column = -1;
                if (row == queens)
                    break;
            }
            else if (column == queens - 1 && chessboard[row][column] != 'Q'){
                row--;
                column = savingposition[row][1];
                chessboard[row][column] = '-';
                column = 0;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------


//---------------------------function to perform refresh board action----------------------------
void removeQueen(){
   for(int i=0;i<queens;i++){
    for(int j=0;j<queens;j++){
      chessboard[i][j] = ' ';
      queenCount=0;
    }
   }
}
//------------------------------------------------------------------------------------------------


//------------------------function to display the game page---------------------------------------
void display_game()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1.0, 0.5, 0.0, 0.0);

    if (displayBlock) {
        glColor3f(0,0,0);
	    displayTitle(800, 650, 0.0, "Congratulations! You've successfully solved it!");
	    displayTitle(840, 610, 0.0, "Now it's time to take on the next level!");

        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
	    glBegin(GL_LINE_LOOP);
        glVertex2f(790, 590);
        glVertex2f(790, 690);
        glVertex2f(1270, 690);
        glVertex2f(1270, 590);
        glEnd();
    }
    //exit button
    glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(850, 200);
		glVertex2f(850 ,150);
		glVertex2f(1200 ,150);
		glVertex2f(1200 ,200);
	glEnd();
	glColor3f(1,1,1);
	displayTitle(800, 50, 0.0, "Note: Refresh the board before Get Solution");
	displayTitle(950, 170, 0.0, "Exit(Press esc)");
	if(mouseX>=850 && mouseX<=1200 && mouseY>=150 && mouseY<=200){
		if(mouseButton){
			viewPage =1;
			mouseButton = false;
		}
	}
    //level down
    glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(850, 275);
		glVertex2f(850 ,225);
		glVertex2f(1200 ,225);
		glVertex2f(1200 ,275);
	glEnd();
	glColor3f(0,0,0);
	displayTitle(930, 245, 0.0, "Level Down(Press s)");

    //level up
    glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(850, 350);
		glVertex2f(850 ,300);
		glVertex2f(1200 ,300);
		glVertex2f(1200 ,350);
	glEnd();
	glColor3f(0,0,0);
	displayTitle(940, 320, 0.0, "Level Up(Press w)");

    //refresh board
    glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(850, 375);
		glVertex2f(850 ,425);
		glVertex2f(1200 ,425);
		glVertex2f(1200 ,375);
	glEnd();
	glColor3f(0,0,0);
	displayTitle(920, 395, 0.0, "Refresh Board(Press d)");

    //Get Solution button
    glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(850, 450);
		glVertex2f(850 ,500);
		glVertex2f(1200 ,500);
		glVertex2f(1200 ,450);
	glEnd();
	glColor3f(0,0,0);
	displayTitle(930, 470, 0.0, "Get Solution!(Press a)");

    displayboard();
    glutSwapBuffers();
}
//------------------------------------------------------------------------------


//------------------adjusts the view port size of game--------------------------
void reshape1(int w, int h){
    glViewport(0, 0, w, h);
    W = w;
    H = h;
}
//------------------------------------------------------------------------------


//------------------------mouse click function of game page---------------------
void mouse(int button, int state, int x, int y) {
    int row, column;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        row = queens - (y / 50) - 1;
        row=queens-row-1;
        column = x / 50;
        if (checking(row, column)){
            chessboard[row][column] = 'Q';
            queenCount++;
        }
        if(queenCount==queens){
            displayBlock = true;
            glutPostRedisplay();
            glutTimerFunc(displayTime, [](int) {
            displayBlock = false;
            glutPostRedisplay(); }, 0);
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        queenCount--;
        row = queens - (y / 50) - 1;
        row=queens-row-1;
        column = x / 50;
        chessboard[row][column] = ' ';
    }
    glutPostRedisplay();
}
//-----------------------------------------------------------------------------


//---------------------Mouse click function of main page-----------------------
void mouseClick(int buttonPressed, int state, int x, int y) {
    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseX = x * 2000 / glutGet(GLUT_WINDOW_WIDTH) - 1000;
        mouseY = -y * 2000 / glutGet(GLUT_WINDOW_HEIGHT) + 1000;
        mouseButton = true;
    }
    else {
        mouseButton = false;
    }
    glutPostRedisplay();
}
//-----------------------------------------------------------------------------


//-------------------Keyboard click function of main page----------------------
void keyboard(unsigned char key, int x, int y){
    if (key == 13) {
        if (viewPage == 0) {
            viewPage = 1;
            glutPostRedisplay();
        }
    }
    if (key == 27) {
        if (viewPage == 0) {
            exit(0);
        }
    }
}
//-----------------------------------------------------------------------------


//-----------------Keyboard click function of main page------------------------
void keyboard1(unsigned char key, int x, int y){
    if (key ==27) {
            exit(0);
    }
    if (key == 's') {
       queens--;
       if(queens<4){
         queens=4;
       }
      glutPostRedisplay();
    }
    if(key=='w'){
      queens++;
      if(queens>14){
        queens=14;
      }
      glutPostRedisplay();
    }
    if(key=='d'){
      removeQueen();
      glutPostRedisplay();
    }
    if(key=='a'){
      backtracking();
      glutPostRedisplay();
    }
}
//-----------------------------------------------------------------------------


//-----------------------------adjusts the view port size of main page---------
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
//-----------------------------------------------------------------------------


//---------------------game function-----------------------------------
void game(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Queen's Quest");
    glutFullScreen();
    glutDisplayFunc(display_game);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard1);
    glutReshapeFunc(reshape1);
    glutMainLoop();
}
//-----------------------------------------------------------------------------


//-------------------main display function-------------------------------------
void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   if(viewPage==0){
      info_page();
   }else if(viewPage==1){
      start_page();
   }else if(viewPage==2){
      instruction_page();
   }else if(viewPage==3){
      game();
   }
	glFlush();
	glutSwapBuffers();
}
//-----------------------------------------------------------------------------


//------------------------------main function----------------------------------
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("QUEEN'S QUEST");
	glutFullScreen();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(reshape);
	glutMainLoop();
	//return 0;
}
//------------------------------------------------------------------------------
