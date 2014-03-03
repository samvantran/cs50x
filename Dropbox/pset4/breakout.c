//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 15

// lives
#define LIVES 3

// height and width of paddle
#define PADDLEH 10
#define PADDLEW 50

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window, and initialize velocity
    GOval ball = initBall(window);
    double x_velocity = drand48() * 3;
    double y_velocity = drand48() + 2;

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // Check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        // if we get one, have paddle follow cursor
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) / 2;
                setLocation(paddle, x, HEIGHT - 50);
            }
        }
        
        // ball movement
        move(ball, x_velocity, y_velocity);
        if (getX(ball) + RADIUS >= WIDTH)
        {
            x_velocity = -x_velocity;
        }
        else if (getX(ball) <= 0)
        {
            x_velocity = -x_velocity;
        }
        else if (detectCollision(window, ball) == paddle)
        {
            y_velocity = -y_velocity;
        }
        else if (getY(ball) <= 0)
        {
            y_velocity = -y_velocity;
        }
        else if (getY(ball) >= HEIGHT)
        {
            lives--;
            initBall(window);
        }
        pause(10);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int width_spacer = 0;
    int height_spacer = 0;
    for(int i = 0, n = ROWS; i < n; i++)
    {
        for(int j = 0, o = COLS; j < o; j++)
        {
            GRect brick = newGRect(2 + width_spacer, HEIGHT / COLS + height_spacer, 35, PADDLEH);
            setFilled(brick, true);
            
            // set color of bricks for each row
            switch(i)
            {
                case 0: 
                    setColor(brick, "BLUE"); 
                    break;
                case 1: 
                    setColor(brick, "GREEN");
                    break;
                case 2:
                    setColor(brick, "YELLOW");
                    break;
                case 3:
                    setColor(brick, "ORANGE");
                    break;
                case 4:
                    setColor(brick, "RED");
                    break;
            }
            add(window, brick);
            
            // create invisible bricks for spacing purposes
            GRect brick_space = newGRect(50 + width_spacer, HEIGHT / COLS + height_spacer, 5, PADDLEH);
            setFilled(brick_space, true);
            setColor(brick_space, "WHITE");
            add(window, brick_space);
            width_spacer += 40;
        }
            width_spacer = 0;
            height_spacer += 15;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH / 2 - RADIUS, HEIGHT / 2 - RADIUS, RADIUS, RADIUS);
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect((WIDTH / 2) - (PADDLEW / 2), HEIGHT - 50, PADDLEW, PADDLEH);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + RADIUS, y + RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
