#include "main.h"

#include <GLFW/glfw3.h>

#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using String = std::string;

enum Example { A = 0, B };

class Entity {
   protected:
    std::string m_Name;
    String a = "";
    int m_hp;

   public:
    Entity() {
        m_Name = "Entity";

        std::cout << "Create Entity" << std::endl;
    }

    Entity(const std::string name) : m_Name(name), m_hp(0) {
        std::cout << "Create Entity" << std::endl;
    }

    ~Entity() {
        std::cout << "Destroy Entity" << std::endl;
    }

   public:
    virtual const std::string& GetName() const {
        return m_Name;
    }
    virtual const int& GetScore() {
        return m_hp;
    }
};

class Player : public Entity {
   public:
    Player(const std::string name) : Entity(name) {
        this->m_Name = name;
    };

    void Something() const {
    }

   public:
    const std::string& GetName() const override {
        Example e = Example::A;
        std::string c = (char*)("dsadas");

        switch (e) {
            case A:
                printf("A\n");
                break;
            case B:
                printf("B");
                break;
        }

        return m_Name;
    }
};

void PrintName(Entity* e) {
    std::cout << e->GetName() << std::endl;
}

void PrintString(const std::string& name) {
    std::cout << name << std::endl;
}

struct Vector2 {
    float m_X, m_Y;

   public:
    Vector2(float x, float y) : m_X(x), m_Y(y) {};

    Vector2 Add(const Vector2& other) const {
        return Vector2(m_X + other.m_X, m_Y + other.m_Y);
    };

    Vector2 Sub(const Vector2& other) const {
        return Vector2(m_X - other.m_X, m_Y - other.m_Y);
    };

    Vector2 Multiply(const Vector2& other) const {
        return Vector2(m_X * other.m_X, m_Y * other.m_Y);
    };

    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }

    Vector2 operator-(const Vector2& other) const {
        return Sub(other);
    }

    Vector2 operator*(const Vector2& other) const {
        return Multiply(other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
    stream << other.m_X << ", " << other.m_Y;
    return stream;
}

void PrintPlayerName(const Player& player) {
    player.Something();
}

class ScopedPtr {
   private:
    Entity* m_Prt;

   public:
    ScopedPtr(Entity* ptr)
        : m_Prt(ptr) {

          };

    ~ScopedPtr() {
        delete m_Prt;
    }

    Entity* operator->() {
        return m_Prt;
    }
    const Entity* operator->() const {
        return m_Prt;
    }
};

struct Vector3 {
    float x, y, z;
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {

          };
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {
        std::cout << "Copied!" << std::endl;
    };
};

std::ostream& operator<<(std::ostream& stream, const Vector3& other) {
    stream << other.x << ", " << other.y << ", " << other.z;
    return stream;
}

int main() {
    int a = glfwInit();
    std::cout << a << std::endl;
    std::vector<Vector3> positions;
    positions.reserve(3);
    positions.emplace_back(1, 2, 3);
    positions.emplace_back(4, 5, 6);
    positions.emplace_back(7, 8, 9);
}
