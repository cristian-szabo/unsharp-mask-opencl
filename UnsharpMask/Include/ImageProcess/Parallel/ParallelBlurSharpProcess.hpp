#pragma once

#include "ImageProcess\ParallelSharpProcess.hpp"

class UNSHARP_MASK_PUBLIC ParallelBlurSharpProcess : public ParallelSharpProcess
{
public:

    ParallelBlurSharpProcess(
        cl::Context context, std::uint32_t radius, 
        float alpha, float beta, float gamma);

    virtual ~ParallelBlurSharpProcess();

    virtual bool create() override;

protected:

    virtual ProgramEntry getProgramSource() override;

    virtual void onBeforeExecute(PPM & image) override;

};
