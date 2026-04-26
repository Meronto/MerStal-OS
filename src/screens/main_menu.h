#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>

void main_menu_handle_event(SDL_Event *event);
void main_menu_update(void);
void main_menu_render(SDL_Renderer *renderer);
void main_menu_init(SDL_Renderer *renderer);
void main_menu_cleanup(void);

#endif
