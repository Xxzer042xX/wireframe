# Render & Zoom Systems

## Main Render Loop
```c
int render(t_app *app)
```
- Vérifie état application
- Dessine carte
- Met à jour fenêtre
- Termine la boucle si STATE_KILL

## Zoom System
```c
void zoom(t_app *app, float factor)
```
1. Modifie facteur zoom
2. Redimensionne image

### Redimensionnement
```c
static void resize_image(t_app *app)
```
1. Détruit image existante
2. Crée nouvelle image
3. Obtient adresse buffer
4. Redessine carte
5. Met à jour affichage

## Color System (Inactif)
```c
void set_colors_point(t_app *app, int num_line, int point)
```
- Configuration couleurs RGB+Alpha
- Non utilisé actuellement

Voulez-vous voir d'autres fichiers à documenter ?