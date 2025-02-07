# So_long


[Screencast from 02-07-2025 12:17:38 PM.webm](https://github.com/user-attachments/assets/29bdd461-5b41-40ac-8c08-94bad4809966)

so_long est un projet de l'école 42 qui consiste à créer un petit jeu en 2D utilisant la bibliothèque **MiniLibX**. L'objectif est de programmer un jeu où le joueur doit récupérer des objets et atteindre une sortie en évitant des ennemis.

## 🚀 Fonctionnalités

- Chargement et affichage d'une carte à partir d'un fichier `.ber`
- Déplacement du personnage (haut, bas, gauche, droite)
- Collecte d'objets
- Détection et gestion des collisions
- Condition de victoire et défaite
- Gestion des touches pour quitter le jeu

## 🎮 Utilisation

Pour lancer et compiler le projet :

```bash
make run // Compil et lance avec bonus
make // Compil
```

Lancer le jeu avec une carte differente :

```bash
./so_long <nom>.ber
```

## 📜 Format de la carte

Les cartes doivent être des fichiers `.ber` respectant les règles suivantes :

- Composées uniquement des caractères `0` (sol), `1` (mur), `P` (joueur), `C` (collectible), `E` (sortie)
- Doivent être entourées de murs (`1`)
- Contenir au moins une sortie (`E`), un joueur (`P`) et un collectible (`C`)

Exemple de carte valide :

```
11111
1P0C1
100E1
11111
```

## ⌨️ Commandes

| Touche | Action         |
|--------|---------------|
| W / ↑  | Aller en haut  |
| A / ←  | Aller à gauche |
| S / ↓  | Aller en bas   |
| D / →  | Aller à droite |
| ESC    | Quitter le jeu |

## 🛠️ Compilation et nettoyage

- Compiler : `make`
- Nettoyer les fichiers objets : `make clean`
- Nettoyer complètement : `make fclean`
- Recompiler : `make re`

## 🏆 Objectifs pédagogiques

- Manipulation des images et événements avec MiniLibX
- Gestion des entrées utilisateur
- Lecture et validation de fichiers
- Optimisation des performances en C
  
---

✨ Bon jeu ! 🎮

