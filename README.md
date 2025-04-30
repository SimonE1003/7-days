<h1 align="center">ENGG1340 group project Group 66</h1>

###

<h2 align="center">Team members:</h2>

<p align="center">(Sort by alphabetical order)<br>Kim Youngseo - 3036446042 <br>Lin Chung Hay Brandon - 3036451578 <br>Sun Jinnan - 3036289688 <br>Sun Yi-Tsen - 3036385767 <br>Wang Yuming - 3036297386 <br>Zhang Jiahao - 3036291679</p>

###

<h2 align="left">Game description:</h2>

###

<p align="left">This is a text-based game called "7 Days", where the player tries to survive for 7 days in a post-apocalyptic world. Try to collect the necessary items and make the right choices in random events! <br><br>The player has status indicators, including health, hunger, thirst, and sanity, as well as an item list that includes food, water, bullets, and more. These will be crucial during gameplay and also a big event after seven days of survival. Through all of this, you will win!<br><br>The game offers different difficulty choices, which would influence probability in random events and the changes in player status. Players can also save the game for the next time they play!</p>

###

<h3 align="left">Factors influence your survival:</h3>

###

<p align="left">Hunger, thirst, sanity, illness, and other items.<br><br>	1. After night, if hunger, thirsty, sanity is insufficient -> health decreases, if ill over zero -> health decreases<br>	2. Through event-> sanity change<br>	3, You can collect food and water to avoid hunger and thirst (they are automatically consumed after night)<br>	4. You can collect medicine at specific locations, which will reduce illness by 1 and add to your health (medicines are automatically used upon collection). <br> 5. Bullets are important! Try to gather them to prepare for battles<br> 6. No health -> bad endings (there are many different endings)</p>

###

<h3 align="left">What should the player do:</h3>

###

<p align="left">1. Daytime: you have to go out and collect items, walk to the door, and choose a destination.<br>	2. Night time: important story happens at the shelter<br>	3. Both night and daytime show the same story. <br> 4. After 7 days, something happens, so prepare well</p>

###

<h3 align="left">Important keys:</h3>

###

<p align="left">1. In shelter: S-> save, E-> Exit (No automatic saving! Please make sure you save your game before exit)<br>	2. Outside: S-> story<br>	3. Press I to check your status</p>

###

<h2 align="left">Implemented Features:</h2>


<p align="left">1. Generation of random events: <br>
<blockquote>In each map (hospital, weapon shop, supermarket, etc.), there are randomly generated stories that the player could trigger, which lead to different rewards/punishments. Each night, a random (and non-repeating) story will be generated. These stories will also have random branches to enhance the user experience further. The possibility of each outcome is affected by game difficulty.</blockquote>
<br>2. Data structures for storing data: <br>
<blockquote>The team used STL::vector for saving Items that the player owns. Text-based graphs are stored in a two-dimensional array and transformed to STL::vector for passing by value through functions. Several structures are applied for saving the content of stories and the player's game status (health, resources, lived days, etc.).</blockquote>
<br>3. Save and load:
<blockquote>This game allows the player to save their game status (health, resources, lived days, etc), items they own, and stories they have experienced. The team ensures that the player retrieves the same game status and does not encounter stories they have already met when loading a game. </blockquote>
<br>4. Dynamic memory management:
<blockquote>Content of stories are in the format of a self-defined structure: struct story. The variables are declared as pointers, and a story is linked to its sequential stories in a linked list format, which includes dynamic memory management. Those variables are then appended to an integer array. </blockquote>
<br>5. File input/output (e.g., for loading/saving data):
<blockquote>The game uses file input/output to realize the Save and Load function. </blockquote>
<br>6. Multiple Difficulty Levels: <br>
<blockquote>The game has easy, medium, and hard modes, which are achieved by varying the status change after each day, the possibility of story outcomes, and the difficulty of the boss fight.
</blockquote></p>
  
<h2 align="left">Compilation/execution instructions:</h2>


<p align="left">Enter the following command in the main directory<br> make run -> run the game<br> make clean -> clean all compile files<br> make delsave -> delete all save files(Be careful! You will lost all your save!)</p>


<h2 align="left">Code with</h2>

###

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="40" alt="cplusplus logo"  /><img src="https://i0.wp.com/easydatadoesit.org/wp-content/uploads/2022/03/makefiles-logo.png?resize=800%2C576&ssl=1" height="40" alt="cplusplus logo"  />
</div>

###
