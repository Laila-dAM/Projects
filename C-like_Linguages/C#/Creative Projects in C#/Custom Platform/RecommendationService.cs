public class RecommendationService {
private readonly List<Course>_courses;
private readonly List<Student>_students;

public RecommendationService(List<Course> courses, List<Student> students) {
    _courses = courses;
    students = students;
}
public List<Course> GetRecommendedCourses(int studentId) {
    var student = _students.FirstOrDefault(s => s.Id == studentId);
if(student == null) return new List<Course>();
    return_courses
.Where(c => c.Modules.Any(m => !student.CompletedModules.Contains(m.Id)))
.OrderByDescending(c => CalculateCourseRecommendationScore(student, c))
.ToList();
}
private double CalculateCourseRecommendationScore(Student student, Course course) {
    double score = 0;
    foreach (var module in course.Modules) {
if(!student.CompletedModules.Contains(module.Id)){
    score += 10;
}
}
return score;
}
}