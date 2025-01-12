using System;
using System.Collections.Generic
using System.Linq;

class Program {
    static void Main(string[] args) {
        Console.WriteLine("Welcome to the AI Evolution Simulato!");
        console.Write("Enter climate type (hot, cold, neutral): ");
        string climate = Console.ReadLine().ToLower();

        Console.Write("Enter mutation rate (0.01 - 1.0): ");
        double mutationRate = double.Parse(Console.ReadLine());

        Console.Write("Enter resource scarcity level (low, medium, high): ");
        string resourceScarcity = Console.ReadLine().ToLower();

        Console.Write("Enter number of generations to simulate: ");
        int generations = int.Parse(Console.ReadLine());

        Console.Write("Enter initial population size: ");
        int populationSize = int.Parse(Console.ReadLine());

        EvolutionSimulator simulator = new EvolutionSimulator(climate, mutationRate, resourceScarcity, populationSize);
        simulator.RunSimulation(generations);
    }
}
class EvolutionSimulator {
    private string Climate;
    private double MutationRate;
    private string ResourceScarcity;
    private List<Pokemon> Population;
    private Random RandomGenerator;

public EvolutionSimulator(string climate, double mutationRate, string resourceScarcity, int populationSize) {
    Climate = climate;
    MutationRate = mutationRate;
    ResourceScarcity = resourceScarcity;
    RandomGenerator = new Random();
    Population = GenerateInitialPopulation(populationSize);
}
public void RunSimulation(int generations) {
    for(int generation = 1; generation <= generations; generation++) {
        EvaluateFitness();
        Reproduce();
        Mutate();

            Console.WriteLine($"Generation {generation}: Average Fitness = {Population.Average(p => p.Fitness):F2}, Population Size = {Population.Count}");
    }
Console.WriteLine("Simulation Complete!");
}
private List<Pokemon> GenerateInitialPopulation(int size){
    var initialPopulation = new List<Pokemon>();
    for(int i = 0; i < size; i++) {
                    initialPopulation.Add(new Pokemon(RandomGenerator.Next(1, 101), RandomGenerator.Next(1, 101), RandomGenerator.Next(1, 101)));

    }
    return initialPopulation;
}
private void EvaluateFitness() {
    foreach (var pokemon in Population) {
        pokemon.Fitness = CalculateFitness(pokemon);
    }
        Population = Population.OrderByDescending(p => p.Fitness).Take(Population.Count / 2).ToList();
}

private double CalculateFitness(Pokemon pokemon) {
    double fitness = 0;
    if(Climate == "hot") {
        fitness += pokemon.Speed * 1.5;
    }
    else if (Climate == "cold"){
        fitness += pokemon.Defense * 1.5;
    }
    else {
        fitness += pokemon.Power;
    }
    if(ResourceScarcity == "high"){
        fitness -= pokemon.Speed * 0.5;
    }
    else if (ResourceScarcity == "low") {
        fitness += pokemon.Power * 0.5;
    }
    return Math.Max(fitness, 0);
}
private void Reproduce() {
    var newGeneration = new List<Pokemon>();
    while(newGeneration.Count < Population.Count * 2) {
        Pokemon parent1 = Population[RandomGenerator.Next(Population.Count)];
            Pokemon parent2 = Population[RandomGenerator.Next(Population.Count)];

            newGeneration.Add(parent1.Mate(parent2));
    }
    Population = newGeneration;
}
private void Mutate() {
    foreach (var pokemon in Population){
        if(RandomGenerator.NextDouble() < MutationRate) {
            pokemon.Mutate();
            
        }
    }
}
}
class Pokemon {
    public int Speed{get; private set;}
    public int Power {get; private set;}
    public int Defense {get; private set;}
    public double Fitness {get; set;}
    private Random RandomGenerator;
    public Pokemon(int speed, int power, int defense) {
        Speed = speed;
        Power = power;
        Defense = defense;
        Fitness = 0;
        RandomGenerator = new Random ();
    }
public Pokemon Mate(Pokemon partner){
    int newSpeed = (Speed + partner.Speed) / 2;
    int newPower = (Power + partner.Power) / 2;

    return new Pokemon(newSpeed, newPower, newDefense);
}
public void Mutate(){
    int mutation = RandomGenerator.Next(-10, 11);

switch(RandomGenerator.Next(3)) {
    case 0:
    Speed = Math.Max(1, Speed + mutation);
    break;
    case 1:
    Power = Math.Max(1, Power + mutation);
    break;
    case 2:
    Defense = Math.Max(1, Defense + mutation);
    break;
}
}
}