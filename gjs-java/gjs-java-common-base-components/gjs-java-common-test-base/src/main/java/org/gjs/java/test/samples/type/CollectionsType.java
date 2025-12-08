package org.gjs.java.test.samples.type;

import java.math.BigDecimal;
import java.util.List;
import java.util.Map;
import java.util.Set;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class CollectionsType {
    private List<Integer> coiVal;
    private Set<Long> colVal;
    private Map<Character, Double> mocdVal;
    private List<BigDecimal> cdecVal;

    public CollectionsType() {
    }
}
