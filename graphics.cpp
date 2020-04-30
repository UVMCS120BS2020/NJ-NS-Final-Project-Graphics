#include "graphics.h"
#include "item.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

GLdouble width, height;
int wd;
Rock p1_r;
Paper p1_p;
Scissors p1_s;
Rock p2_r;
Paper p2_p;
Scissors p2_s;
vector<Item> items_vec;
bool draw_p1_rock = false;
bool draw_p1_paper = false;
bool draw_p1_scissors = false;
bool draw_p2_rock = false;
bool draw_p2_paper = false;
bool draw_p2_scissors = false;
bool show_round = false;
bool p1_chose = false;
bool p2_chose = false;

void init() {
    width = 500;
    height = 500;
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
    
    /*
     * Draw here
     */
    if(show_round){
        if(draw_p1_rock)
            p1_r.draw();
        if(draw_p1_paper)
            p1_p.draw();
        if(draw_p1_scissors)
            p1_s.draw();
        if(draw_p2_rock)
            p2_r.draw();
        if(draw_p2_paper)
            p2_p.draw();
        if(draw_p2_scissors)
            p2_s.draw();
    }
    cout << show_round << endl;
    cout << draw_p1_rock << endl;
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
            draw_p1_rock = true;
            p1_chose = true;
            break;
        case 's':
            draw_p1_paper = true;
            p1_chose = true;
            break;
        case 'd':
            draw_p1_scissors = true;
            p1_chose = true;
            break;
        case 'p':
            show_round = true;
            break;
        case 'c':
            show_round = false;
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
            draw_p2_rock = true;
            p2_chose = true;
            break;
        case GLUT_KEY_DOWN:
            draw_p2_paper = true;
            p2_chose = true;
            break;
        case GLUT_KEY_RIGHT:
            draw_p2_scissors = true;
            p2_chose = true;
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

    /*items_vec.resize(5);
    items_vec[0] = p1_r;
    items_vec[1] = p1_p;
    items_vec[2] = p1_s;
    items_vec[3] = p2_r;
    items_vec[4] = p2_p;
    items_vec[5] = p2_s;
     */


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
