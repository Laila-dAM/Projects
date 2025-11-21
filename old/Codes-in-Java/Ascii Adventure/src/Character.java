public class Character{
private String name;
private int health;

public Character(String name, int health){
    this.name = name;
    this.health = health;
}
public void takeDamage(int damage){
    health -= damage;
}
public int getHealth(){
    return health;
}
}