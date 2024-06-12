#include "main.h"

/**
 * done - A function that returns 1 if you close the window or press the escape
 * key. Also handles everything that's needed per frame.
 *
 * @event: An SDL Event
 * @delay: The delay flag (true or false)
 * @keys: A pointer to a boolean array to store key states
 * Return: Boolean success flag (true or false)
 */
bool done(SDL_Event *event, bool delay, const Uint8 *keys)
{
    /* delay gives CPU some free time */
    /* use once per frame to avoid 100% usage of a CPU core */
    if (delay)
        SDL_Delay(5); /* so it consumes less processing power */

    SDL_PollEvent(event);

    /* Check for quit event or Escape key press */
    if (event->type == SDL_QUIT || keys[SDL_SCANCODE_ESCAPE])
        return true;

    return false;
}

/**
 * readKeys - A function that gives value of pressed key to keys array.
 *
 * @keys: A pointer to a boolean array to store key states
 */
void readKeys(Uint8 *keys)
{
    /* Update the event queue */
    SDL_PumpEvents();

    /* Get the current state of the keyboard */
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    /* Copy the key states to the provided array */
    memcpy(keys, keystate, SDL_NUM_SCANCODES);
}
