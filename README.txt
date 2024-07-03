Jetpack Joyride - Daniel Dalal & Tzach Hondiashvili

Jetpack Joyride is an exhilarating action game where players control a character equipped with a jetpack,
navigating through challenging environments, collecting coins, avoiding obstacles, and achieving high scores.
The game is developed using C++ and SFML (Simple and Fast Multimedia Library) for graphics and sound rendering.
The loading screen in Jetpack Joyride utilizes a separate thread for asynchronous resource loading. 
This approach ensures smooth performance and responsive gameplay, allowing players to interact with the game while textures, 
fonts, music, and sound effects are loaded in the background. It enhances user experience by reducing waiting times and optimizing the game's initialization phase.

Overview
In Jetpack Joyride, players take on the role of a character equipped with a powerful jetpack,
flying through dynamically generated levels filled with obstacles and rewards. 
The objective is to collect coins scattered throughout the game while avoiding collisions with zappers, missiles and other hazards. 
The game features an endless mode where players compete for the highest score by surviving as long as possible.

Features
Player Control: Navigate the character using keyboard space control to control the jetpack's thrust.
Collision Detection: Handle interactions between the player, obstacles, and collectible coins.
Game Objects: Zappers, coins, power-ups, missiles, speed boosts, and moving and static objects.
Scoring System: Track score based on collected coins and distance survived.
Sound Effects and Music: Integrated sounds for jetpack thrust, collision effects, and background music.
User Interface: Start and Help buttons, along with a score display and game instructions.

Installation
Install SFML Library: If SFML is not already installed, follow the instructions provided in the included PDF file (SFMLInstallation) located in the main folder.

Build the Project Using CMake:

Navigate to the project directory in your terminal or command prompt.
Create a build directory: mkdir build
Enter the build directory: cd build
Run CMake to generate the build files: cmake ..
Build the project using make or your preferred build tool: make (Linux/Mac) or open the generated solution file in Visual Studio (Windows).
Run the Game:

Launch the game executable from your IDE or directly from the command line.

Headers:
BasicPlayerState.h: Defines the basic player state.
Beam.h: Represents beam obstacle that the player needs to avoid.
ChooseSkinState.h: Handles the logic for allowing players to choose different character skins.
CMakeLists.txt: CMake configuration file for building the Jetpack Joyride project.
Coin.h: Defines coin objects that players collect for points.
Collision.h: Contains collision detection logic for game objects.
CollisionHandling.h: Handles collision responses between game objects.
Command.h: Implements command patterns for handling user input.
Controller.h: Controls game flow and logic, manages game objects.
DefaultMenu.h: Defines the default menu interface and functionality.
DieState.h: Represents the game state when the player character dies.
Enemy.h: base class that Defines enemy characters.
Factory.h: Implements object factories for creating game objects.
FastPlayerState.h: Defines advanced player states with enhanced speed attributes.
GameObjects.h: Base class for all game objects, defining common attributes and methods.
Help.h: Handles in-game help functionalities.
HelpLeft.h: Implements left navigation for help menus.
HelpRight.h: Implements right navigation for help menus.
HelpState.h: Defines the game state for accessing help menus.
KingSkinOption.h: Implements a command for selecting the King character skin.
Lazer.h: Defines lazer obstacles that players must avoid.
LoadingScreen.h: Manages the loading screen interface.
Map.h: Represents the game world map and its components.
MechState.h: Defines the player state for using a mechanical suit.
Menu.h: Defines the game menu interface and functionalities.
MenuState.h: Base class for menu states, defining common menu behaviors.
Missile.h: Implements enemy missiles and their behavior.
MovingObjects.h: Base class for all moving game objects.
Obstacles.h: Defines static obstacles that hinder player progress.
OriginalSkinOption.h: Implements a command for selecting the original character skin.
Pickable.h: Base class for all pickable game objects.
Pig.h: Defines a pig bonus as a pickable object that gives coins.
Player.h: Defines the player character and its interactions.
PlayerState.h: Base class for player states, defining common player behaviors.
PowerUp.h: class for power-up objects.
Resources.h: Manages game resources such as textures and sounds.
Return2Menu.h: Implements a command for returning to the main menu.
ReverserState.h: Defines a player state for controlling gravity.
RunGameState.h: Defines the game state during active gameplay.
Scientist.h: Defines scientist characters.
ScientistBerrySkin.h: Implements a command for selecting the Scientist Berry character skin.
Scoreboard.h: Manages player scores and displays them on screen.
SoldierBerrySkin.h: Implements a command for selecting the Soldier Berry character skin.
SpeedBoost.h: Defines a speed boost power-up.
StartGame.h: Implements a command for starting the game.
StaticObjects.h: Base class for static game objects.


Source Files (CPP):
Alarm.cpp: Implements functionality for alarm objects in the game.
BasicPlayerState.cpp: Implements basic player states such as running, jumping.
Beam.cpp: Implements beam obsticale that the player must avoid.
ChooseSkinState.cpp: Implements logic for allowing players to choose different character skins.
CMakeLists.txt: CMake configuration file for building the Jetpack Joyride project.
Coin.cpp: Implements functionality for coin objects that players collect for points.
Collision.cpp: Implements collision detection logic for game objects.
CollisionHandling.cpp: Handles collision responses between game objects.
Command.cpp: Implements command patterns for handling user input.
Controller.cpp: Implements game flow and logic, and manages game objects.
DefaultMenu.cpp: Implements the default menu interface and functionality.
DieState.cpp: Implements the game state when the player character dies.
Enemy.cpp: Implements enemy characters and their behavior.
Factory.cpp: Implements object factories for creating game objects.
FastPlayerState.cpp: Implements advanced player states with enhanced speed attributes.
GameObjects.cpp: Implements the base class for all game objects, defining common attributes and methods.
Help.cpp: Implements in-game help functionalities.
HelpLeft.cpp: Implements left navigation for help menus.
HelpRight.cpp: Implements right navigation for help menus.
HelpState.cpp: Implements the game state for accessing help menus.
KingSkinOption.cpp: Implements a command for selecting the King character skin.
Lazer.cpp: Implements lazer obstacles that players must avoid.
LoadingScreen.cpp: Manages the loading screen interface and animations.
main.cpp: Main entry point of the Jetpack Joyride game.
Map.cpp: Represents the game world map and its components.
MechState.cpp: Implements the player state for using a mechanical suit.
Menu.cpp: Implements the game menu interface and functionalities.
MenuState.cpp: Implements the base class for menu states, defining common menu behaviors.
Missile.cpp: Implements enemy missiles and their behavior.
MovingObjects.cpp: Implements the base class for all moving game objects.
OriginalSkinOption.cpp: Implements a command for selecting the original character skin.
Pickable.cpp: Implements the base class for all pickable game objects.
Pig.cpp: Implements a pig character as a pickable object.
Player.cpp: Implements the player character and its interactions.
PlayerState.cpp: Implements the base class for player states, defining common player behaviors.
PowerUp.cpp: Implements the base class for power-up objects.
Resources.cpp: Manages game resources such as textures and sounds.
Return2Menu.cpp: Implements a command for returning to the main menu.
ReverserState.cpp: Implements a player state for reversing gravity.
RunGameState.cpp: Implements the game state during active gameplay.
Scientist.cpp: Implements scientist characters with specific behaviors.
ScientistBerrySkin.cpp: Implements a command for selecting the Scientist Berry character skin.
Scoreboard.cpp: Manages player scores and displays them on screen.
SoldierBerrySkin.cpp: Implements a command for selecting the Soldier Berry character skin.
SpeedBoost.cpp: Implements a speed boost power-up.
StartGame.cpp: Implements a command for starting the game.
StaticObjects.cpp: Implements the base class for static game objects.

STL containers used:
List - to store the game objects,enemies,pickables etc.
Vector - to store music,sounds and other unchanged variables.

credit:
during the dvelopment of the project we faced a problem with identefying collisions accuratly,
we ended up finding a github reposetory that helped us with that.
github link: https://github.com/SFML/SFML/wiki/Source%3A-Simple-Collision-Detection-for-SFML-2.

Conclusion
Jetpack Joyride was a challenging yet rewarding project developed over three intensive weeks. 
We dedicated ourselves to crafting engaging gameplay, refining mechanics, and integrating immersive elements like sound and visuals. 
This journey pushed our skills in game development and teamwork, resulting in a game we're proud to share. 
Thank you for exploring Jetpack Joyride—we hope you enjoy playing it as much as we enjoyed creating it!

License
This project is licensed under the Hadassah Academic College students: Daniel Dalal & Tzach Hondiashvili.