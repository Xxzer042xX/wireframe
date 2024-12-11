# Drawing System Documentation

## Core Drawing Functions

### Map Drawing
```c
void draw_map(t_app *app)
```
Dessine la grille complète en:
1. Parcourant chaque point (x,y)
2. Transformant chaque point selon la vue actuelle
3. Dessinant les lignes horizontales et verticales

### Line Drawing (Bresenham's Algorithm)
```c
static void draw_line(t_app *app, t_point start, t_point end)
```
Implémente l'algorithme de Bresenham pour tracer des lignes:
- Calcule deltas et directions
- Gère les erreurs d'accumulation
- Trace pixel par pixel

### Pixel Drawing
```c
static void put_pixel(t_app *app, int x, int y, int color)
```
Place un pixel dans le buffer d'image si les coordonnées sont valides:
- Vérifie les limites de la fenêtre
- Calcule l'offset mémoire
- Écrit la couleur

## Flux de Rendu
1. Transformation des points
2. Tracé des lignes horizontales
3. Tracé des lignes verticales
4. Mise à jour du buffer d'image

Pour compléter la documentation, pouvez-vous me montrer la fonction `transform_point()` ?