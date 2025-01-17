using System;
using Xunit;

public class GameLogicTests
{
    [Fact]
    public void TestExpandBase()
    {
        var resourceManager = new ResourceManager();
        resourceManager.ExpandBase();
        Assert.Equal(80, resourceManager.GetConstructionMaterials());
    }

    [Fact]
    public void TestResourceManagement()
    {
        var resourceManager = new ResourceManager();
        resourceManager.ManageResources();
        Assert.True(resourceManager.AreResourcesManaged());
    }

    [Fact]
    public void TestEventTrigger()
    {
        var eventSystem = new EventSystem();
        eventSystem.TriggerEvent();
        Assert.True(eventSystem.HasTriggeredEvent());
    }

    [Fact]
    public void TestMapRendering()
    {
        var mapRenderer = new MapRenderer();
        var mapOutput = mapRenderer.RenderMap();
        Assert.Contains("#", mapOutput);
    }
}
