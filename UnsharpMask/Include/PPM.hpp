#pragma once

class UNSHARP_MASK_PUBLIC PPM
{
public:

    enum class Mode
    {
        Invalid,
        ASCII,
        Binary,
        MaxCount
    };

    enum class Format
    {
        Invalid,
        INTENSITY,
        LUMINANCE,
        RGB,
        RGBA,
        MaxCount
    };

    PPM(Mode mode = Mode::ASCII);

    bool create(std::int32_t width, std::int32_t height, Format format = Format::RGB);

    bool isReady() const;

    bool convert(Format format);

    bool destroy();

    Mode getMode() const;

    Format getFormat() const;

    std::uint32_t getWidth() const;

    std::uint32_t getHeight() const;

    std::size_t getSize() const;

    void* getData() const;

    bool operator==(const PPM& other);

private:

    bool ready;

    Mode mode;

    std::int32_t width;

    std::int32_t height;

    Format format;

    std::vector<std::uint8_t> data;

    std::size_t getChannels(Format format) const;

};

UNSHARP_MASK_PUBLIC std::ostream& operator<<(std::ostream& output, const PPM& other);

UNSHARP_MASK_PUBLIC std::istream& operator>>(std::istream& input, PPM& other);