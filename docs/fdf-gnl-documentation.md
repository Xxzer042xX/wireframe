# Get Next Line (GNL)

## Core Function
```c
char *get_next_line(int fd)
```
Lit un fichier ligne par ligne, gère buffer statique pour `[OPEN_MAX]` FDs.

## Helper Functions

### File Reading
```c
static char *read_file(int fd, char *static_buffer)
```
- Lecture par blocs `BUFFER_SIZE`
- Accumulation dans buffer statique
- Gestion EOF et erreurs

### Line Extraction
```c
static char *ft_extract_line(char *static_buffer)
```
- Extrait jusqu'au `\n` ou EOF
- Allocation mémoire dynamique
- Conservation newline

### Buffer Management
```c
static char *ft_next(char *str)
```
- Mise à jour buffer statique
- Suppression ligne extraite
- Préservation reste

## Sécurité
- Vérification fd et BUFFER_SIZE
- Gestion erreurs lecture
- Protection malloc
- Nettoyage mémoire

Voulez-vous voir d'autres fichiers ?