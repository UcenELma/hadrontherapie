// Include the iostream header for basic input/output operations
#include <iostream>

// Include Geant4 headers for core components:
#include "G4RunManager.hh"  // Manages the overall simulation execution
#include "G4UImanager.hh"   // Handles user interface and commands
#include "G4VisManager.hh"  // Handles visualization aspects
#include "G4VisExecutive.hh" // Concrete implementation for visualization
#include "G4UIExecutive.hh" // Concrete implementation for user interface

int main(int argc, char** argv) {
  // Entry point of the program

  // Create a G4RunManager object to manage the simulation
  G4RunManager* runManager = new G4RunManager();
  // Note: Memory management for `runManager` is handled later.

  // Create a G4UIExecutive object for user interface interaction
  G4UIExecutive* ui = new G4UIExecutive(argc, argv);
  // `argc` and `argv` are arguments passed from the command line.
  // Note: Memory management for `ui` is handled later.

  // Create a G4VisManager object for visualization (optional)
  G4VisManager* visManager = new G4VisExecutive();
  // `visManager` is used for initializing and controlling visualization.
  // Note: Memory management for `visManager` is handled later.

  // Initialize the visualization manager (if used)
  visManager->Initialize();

  // Retrieve the pointer to the global G4UImanager instance
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  // This manager handles user commands and interfaces with visualization and run manager.

  // Start the interactive user interface session
  ui->SessionStart();

  // Program execution ends here

  return 0;  // Indicate successful program termination
}
