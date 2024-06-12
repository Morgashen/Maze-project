#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
    SDL_Instance instance;
    SDL_Event event = {0};
    Uint8 keys[SDL_NUM_SCANCODES] = {0};
    Vector player;
    double time = 0;
    double oldTime = 0;
    bool quit = false;

    player.dirX = -1;
    player.dirY = 0;
    player.posX = 22;
    player.posY = 12;
    player.planeX = 0;
    player.planeY = 0.66;

    /* Start up SDL and create window */
    if (!initialize_SDL(&instance))
    {
        fprintf(stderr, "Failed to initialize!\n");
    }
    else
    {
        while (!quit)
        {
            SDL_SetRenderDrawColor(instance.renderer, 0x0, 0x0, 0x0, 0x0);
            SDL_RenderClear(instance.renderer);

            readKeys(keys);
            quit = done(&event, true, keys);

            if (quit)
                break;

            raycaster(player, &time, &oldTime, &instance, &event, true, keys);
            SDL_RenderPresent(instance.renderer);
        }

        end(&instance);
    }

    return 0;
}
