using System;
class ResourceManager{
private int food = 100;
private int oxygen = 100;
private int energy = 100;
private int constructionMaterials = 100;

public void DisplayResources(){
    Console.WriteLine("Resources:");
    Console.WriteLine($"Food: {food}");
    Console.WriteLine($"Oxygen: {oxygen}");
    Console.WriteLine($"Energy: {energy}");
    Console.WriteLine($"Construction Materials: {constructionMaterials}");

}
public void ExpandBase(){
    if(constructionMaterials >= 20){
    constructionMaterials -= 20;
        Console.WriteLine("Base expanded!");
}
else {
            Console.WriteLine("Not enough construction materials.");
}
}
public void ManageResource() {
    Console.WriteLine("Managing resources...");
}
}