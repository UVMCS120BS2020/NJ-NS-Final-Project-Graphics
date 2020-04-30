#include "graphics.h"
#include "item.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include <memory>
#include <iostream>
#include <vector>
//#include <GL/freeglut.h>

using namespace std;

GLdouble width, height;
int wd;
Rock p1_r;
Paper p1_p;
Scissors p1_s;
Rock p2_r;
Paper p2_p;
Scissors p2_s;
vector<unique_ptr<Item>> items_vec;
bool draw_p1_rock = false;
bool draw_p1_paper = false;
bool draw_p1_scissors = false;
bool draw_p2_rock = false;
bool draw_p2_paper = false;
bool draw_p2_scissors = false;
bool p1_chose = false;
bool p2_chose = false;
int p1_wins = 0;
int p2_wins = 0;
char p1_choice;
char p2_choice;

void init() {
    width = 500;
    height = 500;
}

/* Function taken from StackOverflow here:
 * https://stackoverflow.com/questions/538661/how-do-i-draw-text-with-glut-opengl-in-c */
void PrintString(float x, float y, void *font, const unsigned char* string){
    //char *c;
    //glColor3f(1.0, 1.0, 1.0);
    //glRasterPos2f(x,y);
    //glutBitmapString(font,string);
    char *c;
    int x1 = x;
    for (c = (char *) string; *c != '\0'; c++) {
        glRasterPos2f(x1, y);
        glutBitmapCharacter(font, *c);
        x1 = x1 + glutBitmapWidth(font, *c);
    }
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background window color... TODO right now it only changes color after redisplay is called
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 3.0, 6.0,  // eye position
              0.0, 0.0, 0.0,  // center position (not gaze direction)
              0.0, 1.0, 0.0); // up vector
}


/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-width/2, width/2, -height/2, height/2, -width, width);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glEnable(GL_DEPTH);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_FILL);

    PrintString(-100, 200, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Rock Paper scissors!"));
    PrintString(-160, 185, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Player 1: a = rock s = paper d = scissors"));
    PrintString(-170, 170, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Player 2: <- = rock V = paper -> = scissors"));
    PrintString(-170, 155, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("When round is over, press c to clear the board"));


    PrintString(-170, 110, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Player 1"));
    //if(p1_wins < 0)
    //    PrintString(-60+(p1_wins*13), 120, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("|"));
    PrintString(70, 110, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Player 2"));
    //if(p2_wins > 0)
    //    PrintString(180+(p2_wins*13), 120, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("|"));



    if(p1_chose && p2_chose){
        if(draw_p1_rock) {
            items_vec[0]->draw();
            PrintString(-130, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Rock"));
            p1_choice = 'r';
        }
        if(draw_p1_paper) {
            items_vec[1]->draw();
            PrintString(-130, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Paper"));
            p1_choice = 'p';
        }
        if(draw_p1_scissors) {
            items_vec[2]->draw();
            PrintString(130, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Scissors"));
            p1_choice = 's';
        }
        if(draw_p2_rock) {
            items_vec[3]->draw();
            PrintString(90, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Rock"));
            p2_choice = 'r';
        }
        if(draw_p2_paper) {
            items_vec[4]->draw();
            PrintString(90, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Paper"));
            p2_choice = 'p';
        }
        if(draw_p2_scissors) {
            items_vec[5]->draw();
            PrintString(90, -50, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Scissors"));
            p2_choice = 's';
        }

        switch(p1_choice){
            case 'r':
                if(p2_choice == 'r') {
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Draw!"));
                } else if(p2_choice == 'p'){
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 2 wins!"));
                    p2_wins++;
                } else{
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 1 wins!"));
                    p1_wins++;
                }
                break;
            case 'p':
                if(p2_choice == 'r') {
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 1 wins!"));
                    p1_wins++;
                } else if(p2_choice == 'p'){
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Draw!"));
                } else{
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 2 wins!"));
                    p2_wins++;
                }
                break;
            case 's':
                if(p2_choice == 'r') {
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 2 wins!"));
                    p2_wins++;
                } else if(p2_choice == 'p'){
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13,reinterpret_cast<const unsigned char *>("Player 1 wins!"));
                    p1_wins++;
                } else{
                    PrintString(-200, -200, GLUT_BITMAP_8_BY_13, reinterpret_cast<const unsigned char *>("Draw!"));
                }
                break;
        }
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    switch(key) {
        case 'a':
            if(!p1_chose) {
                draw_p1_rock = true;
                p1_chose = true;
            }
            break;
        case 's':
            if(!p1_chose){
                    draw_p1_paper = true;
                    p1_chose = true;
            }
            break;
        case 'd':
            if(!p1_chose) {
                draw_p1_scissors = true;
                p1_chose = true;
            }
            break;
        case 'c':
            p1_chose = false;
            p2_chose = false;
            draw_p1_rock = false;
            draw_p1_paper = false;
            draw_p1_scissors = false;
            draw_p2_rock = false;
            draw_p2_paper = false;
            draw_p2_scissors = false;
            break;

    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            if(!p2_chose) {
                draw_p2_rock = true;
                p2_chose = true;
            }
            break;
        case GLUT_KEY_DOWN:
            if(!p2_chose) {
                draw_p2_paper = true;
                p2_chose = true;
            }
            break;
        case GLUT_KEY_RIGHT:
            if(!p2_chose) {
                draw_p2_scissors = true;
                p2_chose = true;
            }
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    vector<point> modVert = p1_r.getVerteces();
    for(auto & i : modVert){
        i.x += 220;
    }
    p2_r.setVerteces(modVert);

    modVert = p1_p.getVerteces();
    for(auto & i : modVert){
        i.x += 220;
    }
    p2_p.setVerteces(modVert);

    modVert = p1_s.getVerteces();
    for(auto & i : modVert){
        i.x += 220;
    }
    p2_s.setVerteces(modVert);

    items_vec.push_back(make_unique<Rock>(p1_r));
    items_vec.push_back(make_unique<Paper>(p1_p));
    items_vec.push_back(make_unique<Scissors>(p1_s));
    items_vec.push_back(make_unique<Rock>(p2_r));
    items_vec.push_back(make_unique<Paper>(p2_p));
    items_vec.push_back(make_unique<Scissors>(p2_s));



    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Rock, Paper, Scissor game!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
