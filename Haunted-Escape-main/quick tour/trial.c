#include "raylib.h"
#include <string.h>
#include <stdlib.h>
//textures global variables
Texture2D mainmenu;
Texture2D instructions;
Texture2D inventory;
Texture2D bookshelf;
Texture2D desk;
Texture2D gate;
Texture2D attic;
Texture2D basement;
Texture2D reading_room;
Texture2D investigate_library;

// Load textures in initialization
void LoadGameAssets() {
    mainmenu = LoadTexture("mainmenu.png");
    instructions = LoadTexture("instructions.png");
    inventory = LoadTexture("inventory.png");
    desk = LoadTexture("desk.png");
    basement = LoadTexture("basement.png");
    bookshelf = LoadTexture("bookshelf.png");
    gate = LoadTexture("gate.png");
    reading_room = LoadTexture("reading_room.png");
    attic = LoadTexture("attic.png");
    investigate_library = LoadTexture("investigate_library.png");
    
if (mainmenu.width == 0 || mainmenu.height == 0) {
    DrawText("Error loading texture: mainmenu.png", 10, 40, 20, RED);
}

if (instructions.width == 0 || instructions.height == 0) {
    DrawText("Error loading texture: instructions.png", 10, 40, 20, RED);
}

if (inventory.width == 0 || inventory.height == 0) {
    DrawText("Error loading texture: inventory.png", 10, 40, 20, RED);
}
if (bookshelf.width == 0 || bookshelf.height == 0) {
    DrawText("Error loading texture: bookshelf.png", 10, 40, 20, RED);
}
if (desk.width == 0 || desk.height == 0) {
    DrawText("Error loading texture: desk.png", 10, 40, 20, RED);
}
if (gate.width == 0 || gate.height == 0) {
    DrawText("Error loading texture: gate.png", 10, 40, 20, RED);
}
if (attic.width == 0 || attic.height == 0) {
    DrawText("Error loading texture: attic.png", 10, 40, 20, RED);
}
if (basement.width == 0 || basement.height == 0) {
    DrawText("Error loading texture: basement.png", 10, 40, 20, RED);
}
if (reading_room.width == 0 || reading_room.height == 0) {
    DrawText("Error loading texture: reading_room.png", 10, 40, 20, RED);
}
if (investigate_library.width == 0 || investigate_library.height == 0) {
    DrawText("Error loading texture: investigate_library.png", 10, 40, 20, RED);
}

}
// Global Variables
int hasFlashlight = 0, hasKey = 0, hasMap = 0;
int currentScreen = 0; // Screen navigation
int miniGameSolved = 0; // Track mini-game success
char miniGameInput[20] = {0};
char riddleInput[11] = {0};
int riddleChoice = 0;
    char deskInput[10] = {0};

// Function Declarations
void DrawMainMenu();
void DrawInstructions();
void DrawGame();
void DrawInventory();
void DrawBookshelf();
void DrawDesk();
void DrawGate();
void DrawAttic();
void DrawBasement();
void DrawReadingRoom();
void DrawMiniGame();
void DrawRiddle();

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "HAUNTED LIBRARY ESCAPE");
    LoadGameAssets();
    SetTargetFPS(60);

    // Main Game Loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Screen navigation
        switch (currentScreen) {
            case 0: DrawMainMenu(); break;
            case 1: DrawInstructions(); break;
            case 2: DrawGame(); break;
            case 3: DrawInventory(); break;
            case 4: DrawBookshelf(); break;
            case 5: DrawDesk(); break;
            case 6: DrawGate(); break;
            case 7: DrawAttic(); break;
            case 8: DrawBasement(); break;
            case 9: DrawReadingRoom(); break;
            case 10: DrawMiniGame(); break;
            case 11: DrawRiddle(); break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


// Screen: Main Menu
void DrawMainMenu() {
            
    DrawTexture(mainmenu, 0, 0, WHITE);
    DrawText("Haunted Library Escape", 200, 100, 30, LIGHTGRAY);
    DrawText("1. Start Game", 300, 200, 20, WHITE);
    DrawText("2. Instructions", 300, 250, 20, WHITE);
    DrawText("3. Exit", 300, 300, 20, WHITE);

    if (IsKeyPressed(KEY_ONE)) currentScreen = 2; // Start Game
    if (IsKeyPressed(KEY_TWO)) currentScreen = 1; // Instructions
    if (IsKeyPressed(KEY_THREE)) CloseWindow();   // Exit
}

// Screen: Instructions
void DrawInstructions() {
         
    DrawTexture(instructions, 0, 0, WHITE);
    DrawText("Game Instructions", 300, 100, 30, LIGHTGRAY);
    DrawText("1. Explore the library to escape.", 50, 200, 20, WHITE);
    DrawText("2. Solve puzzles and collect items.", 50, 250, 20, WHITE);
    DrawText("3. Beware of traps and dead ends.", 50, 300, 20, WHITE);
    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);

    if (IsKeyPressed(KEY_N)) currentScreen = 0;
}

// Screen: Game (Explore Library)
void DrawGame() { 
            DrawTexture(investigate_library,0, 0, WHITE);
    DrawText("Where will you start exploring?", 150, 100, 25, LIGHTGRAY);
    DrawText("0. Check Inventory", 200, 200, 20, WHITE);
    DrawText("1. Bookshelf", 200, 250, 20, WHITE);
    DrawText("2. Desk", 200, 300, 20, WHITE);
    DrawText("3. Attic (Requires Flashlight)", 200, 350, 20, WHITE);
    DrawText("4. Basement (Requires Key)", 200, 400, 20, WHITE);
    DrawText("5. Reading Room", 200, 450, 20, WHITE);
    DrawText("6. Gate", 200, 500, 20, WHITE);

    // Debugging output for key press detection
    if (IsKeyPressed(KEY_FIVE)) {
        currentScreen = 9; // Reading Room
        DrawText("You pressed 5!", 200, 550, 20, GREEN);  // Debugging message
    }

    // Other input conditions for other actions
    if (IsKeyPressed(KEY_ZERO)) currentScreen = 3; // Inventory
    if (IsKeyPressed(KEY_ONE)) currentScreen = 4; // Bookshelf
    if (IsKeyPressed(KEY_TWO)) currentScreen = 5; // Desk
    if (IsKeyPressed(KEY_THREE) && hasFlashlight) currentScreen = 7; // Attic (Requires Flashlight)
    if (IsKeyPressed(KEY_FOUR) && hasKey) currentScreen = 8; // Basement (Requires Key)
    if (IsKeyPressed(KEY_SIX)) currentScreen = 6; // Gate
}


// Screen: Inventory
void DrawInventory() {
            DrawTexture(inventory, 0, 0, WHITE);
    DrawText("Inventory:", 350, 100, 25, LIGHTGRAY);
    if (hasFlashlight) DrawText("- Flashlight", 350, 200, 20, GREEN);
    if (hasKey) DrawText("- Key", 350, 250, 20, GREEN);
    if (hasMap) DrawText("- Map", 350, 300, 20, GREEN);
    if (!hasFlashlight && !hasKey && !hasMap) DrawText("- (Empty)", 350, 200, 20, RED);

    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2;
}

// Screen: Bookshelf
void DrawBookshelf() {
            DrawTexture(bookshelf, 0, 0, WHITE);
    DrawText("You find a flashlight in the bookshelf!", 150, 200, 20, LIGHTGRAY);
    hasFlashlight = 1;

    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2;
}

// Screen: Desk

void DrawDesk() {
            DrawTexture(desk, 0, 0, WHITE);
    DrawText("You search the desk and find a secret drawer.", 100, 200, 20, LIGHTGRAY);
    DrawText("A creepy witch appears and gives you a riddle:", 100, 250, 20, LIGHTGRAY);
    DrawText("'What is half of 6 plus 6?'", 100, 300, 20, RED);
    DrawText("Enter your answer:", 100, 350, 20, GRAY);

    int key = GetKeyPressed();
    if (key >= KEY_ZERO && key <= KEY_NINE) {
        int len = strlen(deskInput);
        if (len < 9) deskInput[len] = key; // Append digit
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(deskInput);
        if (len > 0) deskInput[len - 1] = '\0'; // Remove last character
    }

    DrawText(deskInput, 300, 350, 20, WHITE);

    if (strcmp(deskInput, "9") == 0) {
    hasKey = 1;
    DrawText("Correct! You got the KEY.", 100, 400, 20, GREEN);
    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2; // Return to game
    }
    else {
    DrawText("Wrong! Try again.", 100, 400, 20, RED);
    }
}

// Screen: Gate
void DrawGate() {
            DrawTexture(gate, 0, 0, WHITE);
    
    if (hasKey) {
        DrawText("You unlock the gate and escape the library!", 150, 200, 25, GREEN);
        DrawText("Congratulations! You win!", 200, 300, 30, LIGHTGRAY);
        DrawText("Press [ESC] to exit.", 300, 500, 20, GRAY);
        if (IsKeyPressed(KEY_ESCAPE)) CloseWindow();
    } else {
        DrawText("The gate is locked. Find the key first.", 150, 200, 20, RED);
        DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
        if (IsKeyPressed(KEY_N)) currentScreen = 2;
    }
}

// Screen: Attic
void DrawAttic() {
            DrawTexture(attic, 0, 0, WHITE);
    if (hasFlashlight) {
        DrawText("You use the flashlight to explore the attic.", 100, 200, 20, LIGHTGRAY);
        DrawText("You found a map!", 100, 250, 20, GREEN);
        hasMap = 1;
    } else {
        DrawText("It's too dark to explore the attic.", 100, 200, 20, RED);
        DrawText("Find a flashlight first.", 100, 250, 20, GRAY);
    }

    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2; // Return to game
}

// Screen: Basement
void DrawBasement() {
        DrawTexture(basement, 0, 0, WHITE);
    if (hasKey) {
        DrawText("You unlock the basement door and descend into the dark.", 100, 200, 20, LIGHTGRAY);
        DrawText("Play the mini-game to progress!", 100, 250, 20, WHITE);
        DrawText("Press [ENTER] to start mini-game.", 100, 300, 20, GRAY);

        if (IsKeyPressed(KEY_ENTER)) currentScreen = 10; // Mini-Game screen
    } else {
        DrawText("The basement door is locked. Find the key first.", 100, 200, 20, RED);
    }

    DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2;
}

 // Buffer for riddle answer input
float riddleTimer = 0;     // Timer for displaying the riddle
bool riddleSolved = false; // Track if the riddle was solved

void DrawReadingRoom() {
        DrawTexture(reading_room, 0, 0, WHITE);
    // Display riddle options
    DrawText("The door slams shut behind you!", 100, 200, 20, RED);
    DrawText("You find a riddle written on the wall:", 100, 250, 20, LIGHTGRAY);
    DrawText("IN FRONT OF YOU ARE 3 DOORS!!!", 100, 300, 20, WHITE);
    DrawText("1. A serial killer.", 100, 350, 20, WHITE);
    DrawText("2. A lion starved for a year.", 100, 400, 20, WHITE);
    DrawText("3. A poisonous lake.", 100, 450, 20, WHITE);
    DrawText("Which door do you choose? [1, 2, 3]:", 100, 500, 20, GRAY);

    // Handle key press for riddle answer
    int key = GetKeyPressed();

    // Convert the key code to a character and append to input
    if (key == KEY_ONE || key == KEY_TWO || key == KEY_THREE) {
        int len = strlen(riddleInput);
        if (len < 9) {  // Ensure we don't exceed array bounds
            riddleInput[len] = key - KEY_ONE + '1';  // Convert keycode to character '1', '2', or '3'
            riddleInput[len + 1] = '\0';  // Null-terminate the string
        }
    }

    // Handle backspace input to remove the last character
    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(riddleInput);
        if (len > 0) {
            riddleInput[len - 1] = '\0';  // Remove last character
        }
    }

    // Draw the current input
    DrawText(riddleInput, 300, 550, 20, WHITE);

    // Check the answer and provide feedback when Enter is pressed
    if (IsKeyPressed(KEY_ENTER)) {
        if (strcmp(riddleInput, "2") == 0) {
            DrawText("You chose wisely! The lion is dead.", 100, 600, 20, GREEN);
            DrawText("Press [N] to return to the library.", 300, 650, 20, GRAY);
            if (IsKeyPressed(KEY_N)) {
                currentScreen = 2; // Go back to the main game screen (library)
            }
        } else {
            DrawText("GAME OVER! You made the wrong choice.", 100, 600, 20, RED);
            currentScreen = 0; // Go back to the main menu
        }
    }
}



// Screen: Mini-Game

void DrawMiniGame() {
    DrawTexture(basement, 0, 0, WHITE);

    // Display mini-game instructions
    DrawText("Mini-Game: Unscramble the word 'SOTIUYSRME'.", 50, 50, 20, WHITE);
    DrawText("Enter your answer:", 50, 100, 20, WHITE);

    // Handle text input
    int key = GetKeyPressed();
    if (key >= KEY_A && key <= KEY_Z) {
        int len = strlen(miniGameInput);
        if (len < 19) miniGameInput[len] = key; // Add character
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(miniGameInput);
        if (len > 0) miniGameInput[len - 1] = '\0'; // Remove character
    }
    DrawText(miniGameInput, 50, 150, 20, WHITE);

    // Check the answer
    if (IsKeyPressed(KEY_ENTER)) {
        if (strcmp(miniGameInput, "MYSTERIOUS") == 0) {
            miniGameSolved = 1;
            DrawText("Correct! You found a clue to escape.", 50, 200, 20, GREEN);
        } else {
            DrawText("Wrong! Try again.", 50, 200, 20, RED);
        }
    }

    DrawText("Press [N] to go back.", 50, 250, 20, GRAY);
    if (IsKeyPressed(KEY_N)) currentScreen = 2; // Return to game
}


// Screen: Logic Riddle
void DrawRiddle() {
    DrawTexture(reading_room, 0, 0, WHITE);
    DrawText("Riddle: In front of you are three doors!", 100, 200, 20, LIGHTGRAY);
    DrawText("1. A serial killer.", 100, 250, 20, WHITE);
    DrawText("2. A lion starved for a year.", 100, 300, 20, WHITE);
    DrawText("3. A poisonous lake.", 100, 350, 20, WHITE);
    DrawText("Which door do you choose? [1, 2, 3]:", 100, 400, 20, GRAY);

    if (IsKeyPressed(KEY_ONE)) {
        DrawText("GAME OVER! Killed by the serial killer.", 100, 450, 20, RED);
        currentScreen = 0; // Return to main menu
    }
    if (IsKeyPressed(KEY_TWO)) {
        DrawText("You chose wisely! The lion is dead.", 100, 450, 20, GREEN);
        DrawText("Press [N] to go back.", 300, 500, 20, GRAY);
        if (IsKeyPressed(KEY_N)) currentScreen = 2; // Return to game
    }
    if (IsKeyPressed(KEY_THREE)) {
        DrawText("GAME OVER! Drowned in the poisonous lake.", 100, 450, 20, RED);
        currentScreen = 0; // Return to main menu
    }
}
void UnloadGameAssets() {
    UnloadTexture(mainmenu);
    UnloadTexture(instructions);
    UnloadTexture(inventory);
    UnloadTexture(bookshelf);
    UnloadTexture(desk);
    UnloadTexture(gate);
    UnloadTexture(attic);
    UnloadTexture(basement);
    UnloadTexture(reading_room);
    UnloadTexture(investigate_library);
}
