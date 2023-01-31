[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9905812&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Average Life of a UCR student
 > Your author list below should include links to all members GitHub (remove existing author).
 
Authors:
Alexander Dobmeier, https://github.com/zanderdo
Stefan Vo, https://github.com/Stefan-Vo
Jared Banzuela: https://github.com/JaredBanzuela 
Matusala Kahsay: https://github.com/matu-kahsay

## Project Description
RPG that simulates the average day in the life of a UCR student. We will be implementing a GUI in which the user can interact with. It consists of various buttons and a text input section. The game allows you to choose your gender, school year, major and other characteristics in order to add variability in the game. This game also has a skill point system, where the major you choose impacts the amount of skill in a certain area ie..(intelligence, charisma, strength).This project will include pictures, scenarios, and many other aspects of life at UCR. Throughout the game the player will face various challenges that may hinder or deter you from accomplishing several key tasks. By completing these tasks it brings you closer to the goal of the game, which is to graduate successfully. 

Why is it interesting to us?
 > This project is important to us as it depicts the issue we face as UCR students. On the technical side, this project interests us as game development is a field that we naturally gravitated towards when deciding on a project idea and what better way to step our foot in the door of game development with a text based RPG game that will use a UI software. It is important that we learn the skills of creating a text based RPG game because we understand that the best way to get a sense of the environment of the computer science industry is to develop a complex software with multiple individuals in order to gauge the difficulty and necessary skills to be successful as a team.
languages/tools/technologies we plan to use
C++
Git
Github
VSCode
CMake
Google test Framework
Photoshop
Unreal Engine

input/output of our project:
The input will primarily be in the form of the user pressing buttons on the GUI to indicate what choices they would like to pick.  The output will be in the form of text and pictures of the UCR campus that give the player new options that will progress them through the game.
Features:
Stats (determined by the major the player chooses at the beginning of the game):
Strength
Charisma
Intelligence
Stamina
Health (starts at 100)

Options:
Talk
Run
Fight
Think

Talk:
When talk is chosen, a skill check on charisma is performed.  If the player passes they get by the obstacle, if not something negative happens (Lose health, go into fight or run, lose inventory item, etc.).  If your charisma is high enough, you can even get an item from the enemy,

Run:
When run is chosen, a skill check on stamina is performed.  If the player passes they get by the obstacle, if not something negative happens (Lose health, go into fight or run, lose inventory item, etc.)  Higher chance of going into fight if failed.

Fight:
When fight is selected, the game enters a simulation of the fight.  Computer picks between a few random attacks for both the player and enemy that do varying amounts of damage.  Higher strength means more damage.  Higher stealth means higher chance to dodge an attack.  Intelligence boosts the chance of a critical hit that does more damage than normal.  Computer can decide to “insult” the enemy.  Insult decreases the damage the enemy does and a higher charisma stat means more reduction in damage that the enemy can do.  Your health at the end of the fight becomes your new health.  If you win, the defeated enemy drops an item.

Think:
When think is selected, a skill check on is ran on intelligence.  If it passes, the player gets a boost or the enemy gets a debuff in either of the other options.  If it fails, the player is forced into a fight and the enemy gets a free hit.

After passing an enemy
After passing an enemy, certain stats are increased based on the choices that the player made.


In-Between Story Choices:
Go to the Gym (increases strength)
Go to a party (increase charisma)
Study at the Library (increases intelligence)
Eat food (increase stamina)
Go to the hospital (Restore health 50-60 pts)

Inventory System:
Stores items that the player can use to help them.  If the player has an item they can use when they encounter an enemy, there is an additional button to use that item and a brief description of what it will do.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
