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