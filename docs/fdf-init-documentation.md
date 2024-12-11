# FdF Initialization Documentation

## Core Initialization Function
```c
int init_app(t_app *app, int ac, char *av)
```

Initializes the application in sequential steps:
1. Validates command line arguments
2. Initializes application memory
3. Sets up transformation parameters
4. Parses input file
5. Initializes MLX window system
6. Sets up event handlers

### Error Handling
Returns error codes defined in `e_error`:
- `ERR_ARGS`: Invalid argument count
- `ERR_MALLOC`: Memory allocation failure
- `ERR_MLX`: MLX initialization failure
- `SUCCESS`: Successful initialization

## Window Initialization
```c
static int init_mlx(t_app *app)
```

Sets up MLX graphics context:
1. Initializes MLX connection
2. Gets screen dimensions
3. Creates window (half screen size)
4. Creates image buffer
5. Gets image address for pixel manipulation

## Transform Initialization
```c
static void init_transform(t_app *app)
```

Sets default transformation values:
- Spacing: 30.0f (grid spacing)
- Isometric angle: 0.523599f (~30 degrees)
- Zoom: 1.0f
- Scale: 1

## Key Structures

### Main Application (`t_app`)
- Controls overall program state
- Houses window, map, and transform data
- Manages projection mode and altitude settings

### Window Management (`t_win`)
- MLX context and window pointers
- Screen and window dimensions
- Image buffer properties
- Mouse state tracking

### Transformation (`t_transform`)
- Rotation angles (x, y, z)
- Scaling and zoom factors
- Grid spacing
- Isometric projection parameters

