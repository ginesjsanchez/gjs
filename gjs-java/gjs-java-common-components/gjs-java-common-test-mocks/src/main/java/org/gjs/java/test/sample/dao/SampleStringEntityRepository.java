package org.gjs.java.test.sample.dao;

import org.gjs.java.test.sample.model.SampleStringEntity;
import org.springframework.data.jpa.repository.JpaRepository;

public interface SampleStringEntityRepository extends JpaRepository<SampleStringEntity, String> {

}
