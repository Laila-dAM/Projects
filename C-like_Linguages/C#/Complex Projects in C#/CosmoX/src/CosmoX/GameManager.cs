using System;
class GameManager {
private MapRenderer mapRenderer;
private ResourceManager resourceManager;
private EventSystem eventSystem;

public GameManager(){
    mapRenderer = new MapRenderer();
    resourceManager = new ResourceManager();
    eventSystem = new EventSystem();
}
public void StartGame()
{
    while(true){
      mapRenderer.RenderMap();
        resourceManager.DisplayResources();
        eventSystem.TriggerEvent();
        HandlePlayerInput();
}
}
private void HandlePlayerInput() {
    Console.WriteLine("Choose an action: ");
    Console.WriteLine("1. Expand Base");
    Console.WriteLine("2. Explore Area");
    Console.WriteLine("3. Manager Resources");

var choice = Console.ReadLine();
    switch(choice){
       case "1":
        resourceManager.ExpandBase();
        break;
        case "2":
        mapRenderer.ExploreArea();
        break;
        case "3":
        resourceManager.ManageResource();
        break;
        default:
        Console.WriteLine("Invalid option");
        break;
}
}
}