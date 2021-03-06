#pragma once
typedef unsigned int UINT;
#include <d3d12.h>
#include <vector>
#include <string>
namespace SCompile {
	struct ComputeShaderVariable
	{
		enum Type
		{
			ConstantBuffer, StructuredBuffer, RWStructuredBuffer, SRVDescriptorHeap, UAVDescriptorHeap
		};
		std::string name;
		Type type;
		UINT tableSize;
		UINT registerPos;
		UINT space;
		ComputeShaderVariable() {}
		ComputeShaderVariable(
			const std::string& name,
			Type type,
			UINT tableSize,
			UINT registerPos,
			UINT space
		) : name(name),
			type(type),
			tableSize(tableSize),
			registerPos(registerPos),
			space(space)
		{}
	};
	struct Pass
	{
		std::vector<char> vsShaderr;
		std::vector<char> psShader;
		D3D12_RASTERIZER_DESC rasterizeState;
		D3D12_DEPTH_STENCIL_DESC depthStencilState;
		D3D12_BLEND_DESC blendState;
	};

	enum ShaderVariableType
	{
		ShaderVariableType_ConstantBuffer,
		ShaderVariableType_SRVDescriptorHeap,
		ShaderVariableType_UAVDescriptorHeap,
		ShaderVariableType_StructuredBuffer
	};
	struct ShaderVariable
	{
		std::string name;
		ShaderVariableType type;
		UINT tableSize;
		UINT registerPos;
		UINT space;
		ShaderVariable() {}
		ShaderVariable(
			const std::string& name,
			ShaderVariableType type,
			UINT tableSize,
			UINT registerPos,
			UINT space
		) : name(name),
			type(type),
			tableSize(tableSize),
			registerPos(registerPos),
			space(space) {}
	};
	struct PassDescriptor
	{
		std::string name;
		std::string vertex;
		std::string fragment;
		D3D12_RASTERIZER_DESC rasterizeState;
		D3D12_DEPTH_STENCIL_DESC depthStencilState;
		D3D12_BLEND_DESC blendState;
	};
	void GetShaderRootSigData(const std::string& path, std::vector<ShaderVariable>& vars, std::vector<PassDescriptor>& GetPasses);
	void GetComputeShaderRootSigData(const std::string& path, std::vector<ComputeShaderVariable>& vars, std::vector<std::string>& GetPasses);
}