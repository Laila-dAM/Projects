[Route("api/[controller]")]
[ApiController]
public class CourseController : ControllerBase {
    private readonly RecommendationService _recommendationService;

    public CourseController(RecommendationService recommendationService) {
        _recommendationService = recommendationService;
    }
}