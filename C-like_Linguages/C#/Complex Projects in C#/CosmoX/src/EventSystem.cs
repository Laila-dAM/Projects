using System;
class EventSystem{
public void TriggerEvent(){
    Random rand = new Random();
    int eventChance = rand.Next(1, 11);

    if(eventChance <= 3){
    Console.WriteLine("Event triggered: Dust storm!");       
}
else if(eventChance <= 6){
    Console.WriteLine("Event triggered: Equipment malfunction!");
}
else {
    Console.WriteLine("No events this turn");
}
}
}