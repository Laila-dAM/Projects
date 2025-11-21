using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;
[ApiController]
[Route("api/[controller]")]
public class ChatController : ControllerBase {
    private static List<Message> Messages = new List<Message>();

[HttpGet]
public IActionResult GetMessages() {
    return Ok(Messages);
}
[HttpPost]
public IActionResult PostMessage(Message message) {
Messages.Add(message);
return Ok();
}
}