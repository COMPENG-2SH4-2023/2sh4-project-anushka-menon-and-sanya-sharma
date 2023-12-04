[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/gUachAgg)
# COE2SH4-PPA3Template
Project Preparation Activity 3

You must watch the briefing video and read through the manual to engage in the development activities.


Section: [L01 and L08]

MacID: [shars172 and menona18]

StudentID: [4000455262 and 400465619]

Game description: 
The snake game we created begins with a game board bordered with hashtags, scattered with randomly placed snake food and a snake head. Initially, the snakehead has no body segments and occupies a unique, randomly chosen spot, in this case, a given coordinate on the game board. Players navigate the snake through the game board's boundaries using directional keys ('w,' 'a,' 's,'  'd'). As the snake slithers through the game, it eagerly devours each morsel of snake food it encounters. With every successful food intake, the snake's body grows longer by 1 unit, and the player's score increases by 1 point. The challenge lies in keeping the snake moving without allowing its head to collide with its growing body. It also includes a speed feature wherein reaching a certain amount of points increases speed, making it more interesting to play! The game ends when the snake's head hits its body, resulting in "game over."


Additional Feature:
Incorporating a progressive speed increase mechanism into the game after achieving a set level of points. With this feature, the game's speed gradually ramps up after every 5 points scored by the snake. Additionally, the game prompts the user to adapt to the changing pace. Here's how this feature works:

Initial Speed: When the game begins, the gameplay speed starts at a moderate pace, providing a comfortable starting point to get accustomed to the game mechanics.

Incremental Speed: After the player accumulates 5 points, the game dynamically increases speed. This acceleration is used through the MacUILib_Delay. The speed increase can affect various aspects of the game, such as the movement speed of the player's character, the rate at which obstacles appear, or the overall tempo of the gameplay.

User Prompts: Alongside the speed increment, the game displays on-screen prompts to inform the player about the change. This prompt is in the form of text and is mentioned as "Level". For example, the game will display a change in level once the "Your Score" reaches 5, resulting in an increase in speed.

Adaptive Gameplay: With each speed increment, the player is encouraged to adapt quickly to the changing dynamics of the game.
