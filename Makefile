# Nom de l'exécutable final
TARGET = PlatformSimulator

# Répertoires de sources et d'inclusions
SRC_DIR = src
INC_DIR = include

# Répertoires des sources spécifiques
SRC_PLATFORM_DIR = $(SRC_DIR)/platform
SRC_SIMULATION_DIR = $(SRC_DIR)/simulation

# Liste des fichiers source à compiler
SRC_FILES = $(SRC_PLATFORM_DIR)/Conveyor.cpp \
            $(SRC_PLATFORM_DIR)/Dock.cpp \
            $(SRC_PLATFORM_DIR)/Platform.cpp \
            $(SRC_PLATFORM_DIR)/Shelf.cpp \
            $(SRC_PLATFORM_DIR)/Transporter.cpp \
            $(SRC_PLATFORM_DIR)/Warehouse.cpp \
            $(SRC_SIMULATION_DIR)/Simulation.cpp \
            $(SRC_SIMULATION_DIR)/SimulationParams.cpp \
            $(SRC_DIR)/main.cpp  

# Liste des fichiers d'en-tête à inclure
INC_FILES = $(INC_DIR)/platform/Conveyor.h \
            $(INC_DIR)/platform/Dock.h \
            $(INC_DIR)/platform/Driver.h \
            $(INC_DIR)/platform/Entity.h \
            $(INC_DIR)/platform/Location.h \
            $(INC_DIR)/platform/Person.h \
            $(INC_DIR)/platform/PlatformElement.h \
            $(INC_DIR)/platform/Platform.h \
            $(INC_DIR)/platform/Product.h \
            $(INC_DIR)/platform/Shelf.h \
            $(INC_DIR)/platform/Transporter.h \
            $(INC_DIR)/platform/Worker.h \
            $(INC_DIR)/simulation/Simulation.h \
            $(INC_DIR)/simulation/SimulationPlatform.h \
            $(INC_DIR)/platform/Storage.h

# Répertoire des fichiers objets
OBJ_DIR = obj

# Extension des fichiers objets
OBJ_FILES = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_FILES:.cpp=.o))

# Compilateur et options de compilation
CXX = g++
CXXFLAGS = -std=c++11 -I$(INC_DIR) -I$(INC_DIR)/platform -I$(INC_DIR)/simulation -I$(SRC_DIR)

# Règle par défaut pour construire l'exécutable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Règle pour compiler les fichiers source en fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Règle pour nettoyer les fichiers générés (objets et exécutable)
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Règle pour exécuter le programme
run: $(TARGET)
	./$(TARGET)

# Règle pour afficher les fichiers objets générés
obj:
	@echo $(OBJ_FILES)
