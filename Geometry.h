#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vulkan/vulkan.h>
#include <chrono>

#include "Structs.h"

class Matrix {
	// if more functions would use time, it can be stored as singleton's class param
	public:
		static void RotateInTime(UniformBufferObject& ubo, const VkExtent2D &swapChainExtent) {
			static auto startTime = std::chrono::high_resolution_clock::now(); // static makes its lifetime last for the program
			auto currentTime = std::chrono::high_resolution_clock::now(); // The dot operator (.) is for objects, not types
			float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
			ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			ubo.proj = glm::perspective(glm::radians(45.0f), swapChainExtent.width / (float)swapChainExtent.height, 0.1f, 10.0f);
			ubo.proj[1][1] *= -1; // flip coords
		};
};