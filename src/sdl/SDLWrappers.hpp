#pragma once

#include <vector>
#include <optional>
#include <memory>

#include <SDL2/SDL.h>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

constexpr const char *WINDOW_TITLE = "Automation";

namespace automation::sdl
{
    std::vector<SDL_Event> get_events();

    class SDLWrapper
    {
    public:
        SDLWrapper();
        ~SDLWrapper();
    };

    class WindowWrapper
    {
    public:
        WindowWrapper(SDLWrapper &);
        ~WindowWrapper();

        SDL_Window *get();

    private:
        SDL_Window *m_ptr;
    };

    class RendererWrapper
    {
    public:
        RendererWrapper(WindowWrapper &);
        ~RendererWrapper();

        SDL_Renderer *get();

        void set_color(int8_t red, int8_t green, int8_t blue, int8_t alpha = 255);
        void clear();
        void present();

    private:
        SDL_Renderer *m_ptr;
    };

} // namespace automation::sdl
