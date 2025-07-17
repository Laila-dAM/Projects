public class Student {
    public int Id { get; set; }
    public string Name { get; set; } = string.Empty;               
    public double PerformanceScore { get; set; }
    public List<int> CompletedModules { get; set; } = new List<int>(); 
}
