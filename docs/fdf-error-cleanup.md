# Error Handling and Cleanup Systems

## Error Management
```c
int error_exit(int error)
```

### Error Codes
- `ERR_ARGS`: Arguments invalides
- `ERR_MALLOC`: Échec allocation mémoire
- `ERR_FILE`: Échec ouverture fichier
- `ERR_FORMAT`: Format fichier invalide
- `ERR_MLX`: Échec initialisation MLX

### Comportement
- Affiche message d'erreur sur stderr
- Retourne code d'erreur pour propagation

## Cleanup System

### Main Cleanup
```c
void cleanup_app(t_app *app)
```
Orchestration du nettoyage général:
1. Nettoyage map
2. Nettoyage fenêtres

### Map Cleanup
```c
static void cleanup_map(t_app *app, int current_line)
```
- Libère points individuels
- Libère tableau de points
- Sécurise contre NULL

### Window Cleanup
```c
static void cleanup_windows(t_app *app)
```
Séquence de nettoyage MLX:
1. Destruction image
2. Destruction fenêtre
3. Destruction display MLX
4. Libération mémoire MLX
5. Réinitialisation pointeurs

### Sécurité
- Vérifications NULL partout
- Gestion partielle du nettoyage
- Nettoyage ordonné des ressources

Voulez-vous que je documente d'autres aspects spécifiques du projet ?