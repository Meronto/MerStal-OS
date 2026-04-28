#include "main_menu.h"
#include "../config.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

static const char *menu_items[] = {
    "STATUS",
    "MAP",
    "RADIO",
    "LOGS",
    "SETTINGS",
};

static const int menu_count = 5;
static const int selectable_count = 6;
static int selected_item = 0;
static SDL_Texture *button_normal = NULL;
static SDL_Texture *button_selected = NULL;
static SDL_Texture *button_off = NULL;
static SDL_Texture *button_off_selected = NULL;
static TTF_Font *font = NULL;

static void draw_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_FRect rect) {
    SDL_Color color = {133, 124, 11, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, text, 0, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    SDL_RenderTexture(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void main_menu_init(SDL_Renderer *renderer){
    button_normal = IMG_LoadTexture(renderer, "src/assets/texture/button_texture.png");
    button_selected = IMG_LoadTexture(renderer, "src/assets/texture/button_texture_active.png");
    button_off = IMG_LoadTexture(renderer, "src/assets/texture/button_off.png");
    button_off_selected = IMG_LoadTexture(renderer, "src/assets/texture/button_off_select.png");
    font = TTF_OpenFont("src/assets/fonts/IBMPlexMono-Regular.ttf", 24);
    if (!button_normal || !button_selected || !button_off || !button_off_selected || !font) {
     SDL_Log("Failed to load button textures: %s\n", SDL_GetError());
    }
}

void main_menu_cleanup(void){
    SDL_DestroyTexture(button_normal);
    SDL_DestroyTexture(button_selected);
    SDL_DestroyTexture(button_off);
    SDL_DestroyTexture(button_off_selected);
    TTF_CloseFont(font);
}

void main_menu_handle_event(SDL_Event *event){
    if (event ->type == SDL_EVENT_KEY_DOWN) {
        if (event->key.key == SDLK_LEFT) {
            selected_item--;
            if (selected_item < 0){
                selected_item = selectable_count - 1;
            }

        }
        if (event->key.key == SDLK_RIGHT){
            selected_item++;
            if (selected_item >= selectable_count){
                selected_item = 0;
            }
        }
        if (event->key.key == SDLK_RETURN) {
            switch (selected_item) {
                case 0: {

                }

                    break;
                case 1: {

                }

                    break;
                case 2: {

                }

                    break;
                case 3: {

                }

                    break;
                case 4: {

                }

                    break;
                case 5: {
                    SDL_Event quit_event;
                    quit_event.type = SDL_EVENT_QUIT;
                    SDL_PushEvent(&quit_event);
                    break;
                }
            }
        }
    }

}

void main_menu_update(void){

}

void main_menu_render(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer,4,10,4,255);
    SDL_RenderClear(renderer);
    SDL_FRect top_bar = {
        .x = 20.0f,
        .y = 20.0f,
        .w = 800.0f,
        .h = 50.0f
    };
    SDL_SetRenderDrawColor(renderer,31,33,33,255);
    SDL_RenderFillRect(renderer,&top_bar);

    for (int i = 0; i < menu_count; i++){
        SDL_FRect button = {
            .x = 30.0f + i * 145.0f,
            .y = 27.0f,
            .w = 128.0f,
            .h = 36.0f
        };
        if (i == selected_item){
            SDL_RenderTexture(renderer, button_selected, NULL, &button);
        } else {
            SDL_RenderTexture(renderer, button_normal, NULL, &button);
        }
        SDL_FRect text_rect = {
            .x = button.x + 10.0f,
            .y = button.y + 5.0f,
            .w = button.w - 20.0f,
            .h = button.h - 10.0f
        };
        draw_text(renderer, font, menu_items[i], text_rect);
        SDL_RenderRect(renderer,&button);
    }

    SDL_FRect button_off_texture = {
        .x = 760.0f,
        .y = 27.0f,
        .w = 36.0f,
        .h = 36.0f
    };
    if (selected_item == selectable_count - 1){
        SDL_RenderTexture(renderer, button_off_selected, NULL, &button_off_texture);
    } else {
        SDL_RenderTexture(renderer, button_off, NULL, &button_off_texture);
    }
    SDL_FRect content = {
        .x = 20.0f,
        .y = 90.0f,
        .w = 760.0f,
        .h = 350.0f
    };
    SDL_SetRenderDrawColor(renderer,60,160,70,255);
    SDL_RenderRect(renderer, &content);
}
