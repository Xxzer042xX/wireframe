# FdF File Parser Documentation

## Structure Générale
```c
int parse_file(t_app *app, char *filename)
```

### Étapes de Parsing
1. Comptage lignes (`count_line`)
2. Allocation mémoire carte
3. Lecture et traitement (`parse_file_process`)

## Processus de Lecture
```c
static int parse_file_process(t_app *app, char *filename)
```
- Lecture ligne par ligne (GNL)
- Validation format
- Stockage données

## Validation Format
```c
static int parse_line(t_app *app, char *line, int num_line)
```
- Split ligne en tokens
- Vérification largeur constante
- Allocation mémoire points

## Parsing Z et Couleurs
```c
int parsing_z(t_app *app, char *z_value, int num_line, int col)
```
- Format: `z,color` (ex: "10,0xFF0000")
- Validation nombres/hexadécimal
- Stockage hauteur et couleur

## Gestion Erreurs
- `ERR_FILE`: Fichier invalide/inaccessible
- `ERR_MALLOC`: Échec allocation
- `ERR_FORMAT`: Format incorrect
- `ERR_DATA`: Données invalides

## Structures de Données
- Points stockés dans `app->map.points[y][x]`
- Coordonnées (x,y,z)
- Couleurs (RGB/hex)

Pouvez-vous me montrer le fichier `render.c` pour documenter le processus de rendu ?