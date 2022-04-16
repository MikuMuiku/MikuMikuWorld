#pragma once
#include "Quad.h"
#include "../Math.h"
#include "Texture.h"
#include "AnchorType.h"
#include "VertexBuffer.h"
#include <vector>
#include <array>

namespace MikuMikuWorld
{
	constexpr size_t maxVertices = 10000;
	constexpr size_t maxIndices = 15000;
	constexpr size_t maxQuads = 2500;

	class Renderer
	{
	private:
		size_t numVertices;
		size_t numBatchVertices;
		size_t numIndices;
		size_t numQuads;
		size_t numBatchQuads;

		VertexBuffer vBuffer;
		std::vector<Quad> quads;
		std::array<DirectX::XMVECTOR, 4> vPos;
		std::array<DirectX::XMVECTOR, 4> uvCoords;

		unsigned int vao, vbo, ebo;
		int texID;
		bool batchStarted;

		void init();
		void resetRenderStats();

	public:
		Renderer();

		void drawSprite(const Vector2& pos, const float rot, const Vector2& sz, const AnchorType anchor, const Texture& tex, int spr, const Color& tint, int z = 0);
		void drawSprite(const Vector2& pos, const float rot, const Vector2& sz, const AnchorType anchor, const Texture& tex,
			float x1, float x2, float y1, float y2, const Color& tint = {1.0f, 1.0f, 1.0f, 1.0f}, int z = 0);
		void drawRectangle(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, const Texture& tex, float x1, float x2, float y1, float y2,
			const Color& tint = { 1.0f, 1.0f, 1.0f, 1.0f }, int z = 0);

		void drawRectangle(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, const Texture& tex, float x1, float x2, float y1, float y2,
			const Color& tint = { 1.0f, 1.0f, 1.0f, 1.0f }, int z = 0);

		void drawQuad(Vector3 pos, Vector3 rot, Vector3 scale, AnchorType anchor, const Texture& tex, int spr, int z = 0);
		void drawQuad(Vector3 pos, Vector3 rot, Vector3 scale, AnchorType anchor, const Texture& tex,
			float x1, float x2, float y1, float y2, Color tint = { 1.0f, 1.0f, 1.0f, 1.0f }, int z = 0);

		void setUVCoords(const Texture& tex, float x1, float x2, float y1, float y2);
		void setAnchor(AnchorType type);
		DirectX::XMMATRIX getModelMatrix(const Vector3& pos, const Vector3& rot, const Vector3& sz);

		void pushQuad(const std::array<DirectX::XMVECTOR, 4>& pos, const std::array<DirectX::XMVECTOR, 4>& uv,
			const DirectX::XMMATRIX& m, const DirectX::XMVECTOR& col, int tex, int z);

		void bindTexture(int tex);
		void beginBatch();
		void endBatch();
		void flush();

		inline int getNumVertices() const { return numBatchVertices; }
		inline int getNumQuads() const { return numBatchQuads; }
	};
}
