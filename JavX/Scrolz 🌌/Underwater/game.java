import javax.swing.*;
public class game {
static char[][] map = new char[10][30];
static int playerX = 0, playerY = 5;
static int score = 0;
static boolean gameRunning = true;

public static void main(String[] args) {
createMap();
while (gameRunning) {
displayMap();
movePlayer();
checkCollision();
popUp("Collect pearls and avoid predators! ٩(^ᗜ^ )و");
}
}
public static void createMap(){
for(int i = 0; i < 10; i++){
for(int j = 0; j < 30; j++){
if(i == 0 || i == 9){
    map[i][j] = '=';
}
else if(j == 0 || j == 29){
map[i][j] = '|';
}
else[i][j] = ' ';
}
}
}
map[2][5] = '*';
map[3][10] = '*';
map[7][20] = 'X';
map[6][15] = 'X';

map[playerY][playerX] = 'O';
}
public static void displayMap(){
StringBuilder sb = new StringBuilder();
for(int i = 0; i < 10; i++){
for(int j = 0; j < 30; j++){
sb.append(map[i][j]);
}
sb.append("\n");
}
System.out.println(sb.toString());
System.out.println("Score: " + score);
}
public static void movePlayer(){
String direction = JOptionPane.showInputDialog("Move (WASD):");
if(direction != null){
direction = direction.toUpperCase();
map[playerY][playerX] =' ';

if(direction.equals("W") && playerY > 1){
playerY--;
}
else if(direction.equal("S") && playerY < 8){
playerY++;
}
else if (direction.equals("A") && playerX > 1){
playerX--;
}
else if (direction.equal("D") && playerX < 28){
playerX++;
}
map[playerY][playerX] = 'O'; 
}
}
public static void checkCollision() {
}