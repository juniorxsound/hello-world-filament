#include <chrono>
#include <iostream>
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/Scene.h>
#include <filament/View.h>

using namespace filament;

int main(int argc, char** argv) {
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Initialize Filament engine
    Engine* engine = Engine::create();

    // Create a renderer
    Renderer* renderer = engine->createRenderer();

    // Create a view and a scene
    View* view = engine->createView();
    Scene* scene = engine->createScene();

    // Basic setup for the view
    view->setScene(scene);

    // Placeholder for the main rendering loop
    // while (appIsRunning) {
    //     if (renderer->beginFrame(swapChain)) {
    //         renderer->render(view);
    //         renderer->endFrame();
    //     }
    // }

    // Clean up
    engine->destroy(view);
    engine->destroy(scene);
    engine->destroy(renderer);
    Engine::destroy(&engine);

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Print the duration to the console
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;

    return 0;
}