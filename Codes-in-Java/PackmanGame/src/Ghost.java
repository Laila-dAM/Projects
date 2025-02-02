public class Ghost{
    private String color;
    private String state = "(¬ºཀ°)¬";

    public Ghost(String color){
        this.color = color;
    }
public String getState(){
    return state;
}
public void die(){
    state = "ʚ(¬ºཀ°)¬";
}
public void escape(){
state = "(\" 0 ﹏  0 )";
}
}