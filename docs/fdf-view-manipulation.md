# View Manipulation Functions

## Window Size Toggle
```c
void toggle_window_size(t_app *app)
void resize_window(t_app *app, int new_width, int new_height)
```

### Window Resizing Process
1. Détruit l'image et fenêtre actuelles
2. Met à jour dimensions
3. Recrée fenêtre et image
4. Réinitialise événements
5. Redessine la carte
6. Alterne entre:
   - Plein écran
   - Demi-écran (dimensions divisées par 2)

## View Toggle
```c
void toggle_view(t_app *app)
```

### Processus de Basculement
1. Inverse le flag isométrique (`app->map.is_iso`)
2. Recrée buffer d'image
3. Redessine carte avec nouvelle projection
4. Rafraîchit affichage

### Séquence MLX
1. Destruction image (`mlx_destroy_image`)
2. Création nouvelle image
3. Obtention adresse données
4. Dessin carte
5. Affichage image

Maintenant, il serait utile de voir la fonction `draw_map()` pour comprendre comment les vues sont rendues. Pouvez-vous me la partager ?