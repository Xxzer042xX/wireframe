# Point Transformation System

## Core Transform Function
```c
t_point transform_point(t_app *app, int x, int y)
```

### Grid Spacing
- Conversion coordonnées grille: `grid_x = x * spacing`
- Espacement configurable via `transform.spacing`

### Projections
#### Isométrique (30°)
```c
iso_x = (grid_x - grid_y) * cos(0.523599)
iso_y = -z + (grid_x + grid_y) * sin(0.523599)
```

#### Parallèle
```c
x = grid_x
y = grid_y
```

### Transformations Appliquées
1. Projection (iso/parallèle)
2. Facteur zoom
3. Centrage:
   ```c
   x += window_width / 2
   y += window_height / 2
   x -= (map_width * zoom * spacing) / 2
   y -= (map_height * zoom * spacing) / 2
   ```

## Flux de Transformation
1. Récupération point original
2. Application espacement grille
3. Calcul projection
4. Application zoom
5. Centrage dans fenêtre

Cette documentation complète le système de rendu du FdF. Voulez-vous que je documente d'autres aspects du projet ?