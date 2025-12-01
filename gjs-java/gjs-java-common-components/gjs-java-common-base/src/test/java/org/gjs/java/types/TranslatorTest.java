package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;

class TranslatorTest extends BaseClassTest<Translator> {

    @Test
    void testTranslator1() {
        final String original = "hola";
        final String translated = "hello";
        final Translator translator = new Translator();
        assertNull(translator.translate(original));

        translator.add(original, translated);
        assertNotNull(translator.translate(original));
        assertEquals(translated, translator.translate(original));

        assertNull(translator.translate("noexiste"));
        assertNull(translator.translate(""));
        assertNull(translator.translate(null));

        final String original2 = "";
        final String translated2 = "";
        translator.add(original2, translated);
        assertNull(translator.translate(original2));
        translator.add(original, translated2);
        assertNotNull(translator.translate(original));
        assertEquals(translated, translator.translate(original));
        translator.add(original2, translated2);
        assertNull(translator.translate(original2));

        translator.add(null, null);
        assertNull(translator.translate(null));

        translator.clear();
        assertNull(translator.translate(original));
    }

}
