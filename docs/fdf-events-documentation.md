# Events System Documentation

## Event Initialization
```c
int init_event(t_app *app)
```
Sets up two core event hooks:
1. Key press events (mask: `1L << 0`)
2. Window close events (mask: `1L << 17`)

Returns `ERR_MLX` on hook failure, `SUCCESS` otherwise.

## Event Handlers

### Window Close Handler
```c
static int handle_exit(t_app *app)
```
Sets application state to `STATE_KILL` when user closes window.

### Key Handler
```c
static int handle_key(int keycode, void *param)
```

Processes keyboard inputs:
- `ESC`: Exit program
- `V`: Toggle view mode
- `A`: Toggle window size
- `+`: Zoom in
- `-`: Zoom out

Debug feature: Prints keycode to stdout.

## Usage Flow
1. Events initialized at program start
2. MLX loop captures user input
3. Input triggers appropriate handler
4. Handler executes corresponding action

Je devrais maintenant voir les fonctions de modification de vue (toggle_view, toggle_window_size, zoom). Pouvez-vous me les partager ?