public class Action {
private String name;
private String kaomojis;

public Action(String name, String kaomojis){
    this.name = name;
    this.kaomojis = kaomojis;
}
public String getKaomojis(){
    return kaomojis;
}
}