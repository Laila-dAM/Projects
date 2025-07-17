using Microsoft.AspNetCore.Mvc;

[Route("api/[controller]")]
[ApiController]
public class CourseController : ControllerBase
{
    private readonly RecommendationService _recommendationService;

    public CourseController(RecommendationService recommendationService)
    {
        _recommendationService = recommendationService;
    }

    [HttpGet]
    public IActionResult GetAllCourses()
    {
        var courses = _recommendationService.GetCourses();
        return Ok(courses);
    }
    [HttpGet("recommendations/{studentId}")]
    public IActionResult GetRecommendedCourses(int studentId)
    {
        var recommendations = _recommendationService.GetRecommendedCourses(studentId);

        if (recommendations == null || recommendations.Count == 0)
        {
            return NotFound($"Nenhuma recomendação encontrada para o aluno com ID {studentId}.");
        }

        return Ok(recommendations);
    }
}