using Microsoft.AspNetCore.Mvc;

[Route("api/[controller]")]
[ApiController]
public class CourseController : ControllerBase {
    private readonly RecommendationService _recommendationService;

    public CourseController(RecommendationService recommendationService) {
        _recommendationService = recommendationService;
    }

    [HttpGet]
    public IActionResult GetCourses() {
        return Ok("API está funcionando!");
    }
}