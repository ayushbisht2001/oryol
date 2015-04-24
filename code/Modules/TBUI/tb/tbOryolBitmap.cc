//------------------------------------------------------------------------------
//  tbOryolBitmap.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "tbOryolBitmap.h"
#include "tbOryolBatchRenderer.h"
#include "tb_bitmap_fragment.h"

namespace Oryol {
namespace _priv {

//------------------------------------------------------------------------------
tbOryolBitmap::tbOryolBitmap(tbOryolBatchRenderer* rnd) :
renderer(rnd),
width(0),
height(0),
label(ResourceLabel::Invalid) {
    // empty
}

//------------------------------------------------------------------------------
tbOryolBitmap::~tbOryolBitmap() {
    if (this->texture.IsValid()) {
        this->destroyTexture();
    }
}

//------------------------------------------------------------------------------
bool
tbOryolBitmap::Init(int w, int h, tb::uint32* data) {
    o_assert_dbg(tb::TBGetNearestPowerOfTwo(w) == w);
    o_assert_dbg(tb::TBGetNearestPowerOfTwo(h) == h);
    this->width = w;
    this->height = h;
    this->createTexture(data);
    return true;
}

//------------------------------------------------------------------------------
void
tbOryolBitmap::SetData(uint32* data) {
    o_assert_dbg(this->texture.IsValid());
    this->destroyTexture();
    this->createTexture(data);
}

//------------------------------------------------------------------------------
void
tbOryolBitmap::createTexture(tb::uint32* data) {
    o_assert_dbg(!this->texture.IsValid());

    // hmm this kinda sucks, a 'view mode' stream would be nice
    const int byteSize = this->width * this->height * sizeof(tb::uint32);
    auto stream = MemoryStream::Create();
    stream->Open(OpenMode::WriteOnly);
    stream->Write(data, byteSize);
    stream->Close();
    
    this->label = Gfx::PushResourceLabel();
    auto texSetup = TextureSetup::FromPixelData(this->width, this->height, 1, TextureType::Texture2D, PixelFormat::RGBA8);
    texSetup.WrapU = TextureWrapMode::Repeat;
    texSetup.WrapV = TextureWrapMode::Repeat;
    texSetup.MinFilter = TextureFilterMode::Nearest;
    texSetup.MagFilter = TextureFilterMode::Nearest;
    texSetup.ImageSizes[0][0] = byteSize;
    this->texture = Gfx::CreateResource(texSetup, stream);
    
    Gfx::PopResourceLabel();
}

//------------------------------------------------------------------------------
void
tbOryolBitmap::destroyTexture() {
    o_assert_dbg(this->texture.IsValid());
    this->renderer->deferDeleteTexture(this->label);
    this->texture.Invalidate();
    this->label = ResourceLabel::Invalid;
}

} // namespace _priv
} // namespace Oryol