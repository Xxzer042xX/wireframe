# FdF Main Function Documentation

## Overview
FdF (Fil de Fer) is a 3D wireframe renderer program. The main function serves as the entry point and handles the core program loop.

## Function Analysis

```c
int main(int ac, char **av)
```

### Parameters
- `ac`: Argument count
- `av`: Array of command line arguments
  - `av[1]`: Expected to contain the path to the map file

### Program Structure
1. **Initialization**
   ```c
   error = init_app(&app, ac, av[1]);
   if (error != SUCCESS)
       return (cleanup_app(&app), error);
   ```
   - Initializes the application with map data
   - Performs error checking
   - Cleans up and exits if initialization fails

2. **Main Loop**
   ```c
   app.state = STATE_RUNNING;
   while (app.state == STATE_RUNNING)
   {
       mlx_loop_hook(app.win.mlx, render, &app);
       mlx_loop(app.win.mlx);
   }
   ```
   - Sets application state to running
   - Enters the MLX rendering loop
   - Continuously calls the render function

3. **Cleanup**
   - On exit, performs cleanup operations
   - Returns SUCCESS status code

## Key Components
- `t_app`: Main application structure containing program state
- `mlx_loop_hook`: Sets up rendering callback
- `mlx_loop`: Maintains program window and handles events

## Return Values
- `SUCCESS`: Program executed successfully
- Other values: Error codes from initialization

## Usage
```bash
./fdf [map_file]
```

This documentation serves as both a technical reference and a defense of implementation choices.
