/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
GuiProjectAudioProcessorEditor::GuiProjectAudioProcessorEditor(
    GuiProjectAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    fargoImage = juce::ImageCache::getFromMemory(BinaryData::fargo_png,
                                                 BinaryData::fargo_pngSize);
    setSize(400 * 2, 300 * 2);
}

GuiProjectAudioProcessorEditor::~GuiProjectAudioProcessorEditor() {}

//==============================================================================
void GuiProjectAudioProcessorEditor::paint(juce::Graphics &g) {

    // (Our component is opaque, so we must completely fill the background with
    // a solid colour)
    g.fillAll(
        getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont(juce::FontOptions(15.0f));
    /* First argument is the text, second argument is the area that dictates the
     bounds with which to draw the text And the third argument is the
     justification */
    g.drawFittedText("Hello Franklin!", getLocalBounds(),
                     juce::Justification::centredTop, 1);
    auto sf = 0.6f;
    auto scaled_height = fargoImage.getHeight() * sf;
    auto scaled_width = fargoImage.getWidth() * sf;

    auto transform = juce::AffineTransform::scale(sf, sf)
                         // To the center
                         // this is terrible and I know JUCE must have some way
                         // of doing this automatically.
                         .translated((getWidth() - scaled_width) / 2,
                                     (getHeight() - scaled_height) / 2);

    g.drawImageTransformed(fargoImage, transform);

    // Here, I'm using .expanded to add padding to the text so it's not so
    // cramped up against the bottom
    g.drawFittedText("Hello Franklin 2!", getLocalBounds().expanded(0, -20),
                     juce::Justification::centredBottom, 1);
}

void GuiProjectAudioProcessorEditor::resized() {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
